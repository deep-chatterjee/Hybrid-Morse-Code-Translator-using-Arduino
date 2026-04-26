"""
Hybrid Morse Code Translator - Python Interface
Connects to Arduino via Serial to send text and display decoded Morse input.

Usage:
  - Type text and press Enter -> Arduino will flash LED + buzzer in Morse
  - Press the button on the Arduino to tap Morse -> decoded text appears here
  - Type 'quit' to exit
"""

import serial
import serial.tools.list_ports
import threading
import time


def list_ports():
    """List all available COM ports."""
    ports = serial.tools.list_ports.comports()
    return [p.device for p in ports]


def choose_port():
    """Let the user pick a COM port."""
    ports = list_ports()

    if not ports:
        print("No COM ports found. Make sure your Arduino is connected.")
        return None

    print("\nAvailable COM ports:")
    for i, port in enumerate(ports):
        print(f"  [{i}] {port}")

    if len(ports) == 1:
        print(f"\nAuto-selecting {ports[0]}")
        return ports[0]

    while True:
        try:
            choice = int(input("\nSelect port number: "))
            if 0 <= choice < len(ports):
                return ports[choice]
        except ValueError:
            pass
        print("Invalid choice. Try again.")


def read_from_arduino(ser):
    """Continuously read and print output from Arduino."""
    while True:
        try:
            if ser.in_waiting > 0:
                line = ser.readline().decode('utf-8', errors='ignore').strip()
                if line:
                    print(f"\n[Arduino] {line}")
                    print("You: ", end='', flush=True)
        except Exception:
            break


def main():
    print("=" * 45)
    print("   Hybrid Morse Code Translator")
    print("=" * 45)

    port = choose_port()
    if not port:
        return

    try:
        ser = serial.Serial(port, 9600, timeout=1)
        time.sleep(2)  # Wait for Arduino to reset
        print(f"\nConnected to {port} at 9600 baud.")
        print("Type text and press Enter to send to Arduino.")
        print("Type 'quit' to exit.\n")

    except serial.SerialException as e:
        print(f"Could not open port {port}: {e}")
        return

    # Start background thread to read Arduino output
    reader = threading.Thread(target=read_from_arduino, args=(ser,), daemon=True)
    reader.start()

    # Main loop: send user input to Arduino
    while True:
        try:
            user_input = input("You: ").strip()

            if user_input.lower() == 'quit':
                print("Closing connection.")
                break

            if user_input:
                ser.write((user_input + '\n').encode('utf-8'))

        except KeyboardInterrupt:
            print("\nExiting.")
            break

    ser.close()


if __name__ == "__main__":
    main()
