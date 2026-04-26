# 🔵 Hybrid Morse Code Translator

> Bidirectional Morse code communication between a laptop and Arduino — text becomes sound and light; button presses become English.

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![Serial](https://img.shields.io/badge/Serial_Comm-PySerial-green?style=for-the-badge)

---

## 📖 Overview

The **Hybrid Morse Code Translator** is a two-way communication system bridging a laptop and an Arduino UNO. It operates in two modes:

- **Text → Morse**: Type any text on your laptop. The Python script encodes it and sends it over serial — the Arduino drives a buzzer and LED to signal the Morse code in real time.
- **Morse → Text**: Press the physical button on the breadboard to tap out Morse code. The Arduino reads the timing of each press, sends it over serial, and the Python script decodes and displays the English translation on screen.

---

## ✨ Features

- 🔁 **Bidirectional** — works in both directions without switching modes manually
- 💡 **Visual + Audio output** — LED flashes and buzzer sounds in sync for every dot and dash
- ⌨️ **Button input** — physical button with debounce logic for accurate timing capture
- 🖥️ **Live terminal display** — decoded text appears character by character as you type in Morse
- 📡 **Serial communication** — clean Arduino ↔ Python protocol over USB

---

## 🛠️ Hardware Components

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| Breadboard | 1 |
| LED (Blue) | 1 |
| Piezo Buzzer | 1 |
| Push Button | 1 |
| Resistor (220Ω) | 1 |
| Jumper Wires | As needed |

---

## 🔌 Circuit Diagram

> Built and simulated in Tinkercad

**Pin Connections:**

| Component | Arduino Pin |
|---|---|
| LED (+ resistor) | Digital 8 |
| Piezo Buzzer | Digital 9 |
| Push Button | Digital 2 |

---

## 🚀 Getting Started

### Prerequisites

- Python 3.x
- Arduino IDE
- PySerial library

```bash
pip install pyserial
```

### Installation

1. **Clone the repository**
```bash
git clone https://github.com/deep-chatterjee/hybrid-morse-translator.git
cd hybrid-morse-translator
```

2. **Upload Arduino sketch**
   - Open `arduino/morse_translator.ino` in the Arduino IDE
   - Select your board: **Arduino UNO**
   - Upload to your board

3. **Run the Python script**
```bash
python morse_translator.py
```

4. **Select your COM port** when prompted (or edit `morse_translator.py` line 5 to set it directly)

---

## 💻 How It Works

### Text → Morse (Laptop to Arduino)

```
User types text
      ↓
Python encodes to Morse (dots & dashes)
      ↓
Sends timing signals over Serial
      ↓
Arduino drives LED + Buzzer accordingly
```

### Morse → Text (Arduino to Laptop)

```
User presses button (dot = short, dash = long)
      ↓
Arduino measures press duration
      ↓
Sends dot/dash pattern over Serial
      ↓
Python decodes Morse → English, prints to screen
```

---

## 📁 Project Structure

```
hybrid-morse-translator/
├── arduino/
│   └── morse_translator.ino   # Arduino sketch (output + input handling)
├── morse_translator.py        # Python script (encoding, decoding, serial comm)
├── morse_code_map.py          # Morse code dictionary
└── README.md
```

---

## 📚 Morse Code Reference

| Character | Morse | Character | Morse |
|---|---|---|---|
| A | `.-` | N | `-.` |
| B | `-...` | O | `---` |
| C | `-.-.` | P | `.--.` |
| D | `-..` | Q | `--.-` |
| E | `.` | R | `.-.` |
| F | `..-.` | S | `...` |
| G | `--.` | T | `-` |
| H | `....` | U | `..-` |
| I | `..` | V | `...-` |
| J | `.---` | W | `.--` |
| K | `-.-` | X | `-..-` |
| L | `.-..` | Y | `-.--` |
| M | `--` | Z | `--..` |

Full map available in `Morse_code_map.md`

---

## 🧠 What I Learned

- Serial communication between Python and Arduino using PySerial
- Timing-based input detection with debounce logic in C++
- Encoding/decoding algorithms for Morse code
- Coordinating hardware outputs (PWM buzzer tones + digital LED) with software signals

---

## 🔮 Future Improvements

- [ ] Add GUI with `tkinter` for a cleaner interface
- [ ] Support full ASCII character set
- [ ] Add audio input (microphone) to decode spoken Morse
- [ ] Wireless version using Bluetooth module (HC-05)

---

## 👤 Author

**Deep Chatterjee**
[GitHub](https://github.com/deep-chatterjee)

---

## 📄 License

This project is licensed under the MIT License — see [LICENSE](LICENSE) for details.
