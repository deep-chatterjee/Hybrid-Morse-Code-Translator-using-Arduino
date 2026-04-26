🔵 Hybrid Morse Code Translator

📖 Overview
The Hybrid Morse Code Translator is a two-way communication system bridging a laptop and an Arduino UNO. It operates in two modes:

Text → Morse: Type any text (alphabets and numbers) on your laptop. The Python script encodes it and sends it over serial - the Arduino drives a buzzer and LED to signal the Morse code in real time.
Morse → Text: Press the physical button on the breadboard to tap out Morse code. The Arduino reads the timing of each press, sends it over serial, and the Python script decodes and displays the English translation on screen.


✨ Features

🔁 Bidirectional - works in both directions without switching modes manually
💡 Visual + Audio output - LED flashes and buzzer sounds in sync for every dot and dash
⌨️ Button input - physical button with debounce logic for accurate timing capture
🖥️ Live terminal display - decoded text appears character by character as you type in Morse
📡 Serial communication - clean Arduino ↔ Python protocol over USB


🛠️ Hardware Components
ComponentQuantityArduino UNO1Breadboard1LED (Blue)1Piezo Buzzer1Push Button1Resistor (220Ω)1Jumper WiresAs needed

🔌 Circuit Diagram

Built and simulated in Tinkercad

Pin Connections:
ComponentArduino PinLED (+ resistor)Digital 8Piezo BuzzerDigital 9Push ButtonDigital 2

🚀 Getting Started
Prerequisites

Python 3.x
Arduino IDE
PySerial library

bashpip install pyserial
Installation

Clone the repository

bashgit clone https://github.com/deep-chatterjee/hybrid-morse-translator.git
cd hybrid-morse-translator

Upload Arduino sketch

Open arduino/morse_translator.ino in the Arduino IDE
Select your board: Arduino UNO
Upload to your board


Run the Python script

bashpython morse_translator.py

Select your COM port when prompted (or edit morse_translator.py line 5 to set it directly)


💻 How It Works
Text → Morse (Laptop to Arduino)
User types text
      ↓
Python encodes to Morse (dots & dashes)
      ↓
Sends timing signals over Serial
      ↓
Arduino drives LED + Buzzer accordingly
Morse → Text (Arduino to Laptop)
User presses button (dot = short, dash = long)
      ↓
Arduino measures press duration
      ↓
Sends dot/dash pattern over Serial
      ↓
Python decodes Morse → English, prints to screen

📁 Project Structure
hybrid-morse-translator/
├── arduino/
│   └── morse_translator.ino   # Arduino sketch (output + input handling)
├── morse_translator.py        # Python script (encoding, decoding, serial comm)
├── morse_code_map.py          # Morse code dictionary
└── README.md

📚 Morse Code Reference
CharacterMorseCharacterMorseA.-N-.B-...O---C-.-.P.--.......
Full map available in morse_code_map.py

🧠 What I Learned

Serial communication between Python and Arduino using PySerial
Timing-based input detection with debounce logic in C++
Encoding/decoding algorithms for Morse code
Coordinating hardware outputs (PWM buzzer tones + digital LED) with software signals


🔮 Future Improvements

 Add GUI with tkinter for a cleaner interface
 Support full ASCII character set
 Add audio input (microphone) to decode spoken Morse
 Wireless version using Bluetooth module (HC-05)


👤 Author
Deep Chatterjee
GitHub

📄 License
This project is licensed under the MIT License — see LICENSE for details.
