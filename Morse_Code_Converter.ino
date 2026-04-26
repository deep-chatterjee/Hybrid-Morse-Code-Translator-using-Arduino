/*
HYBRID MORSE CODE TRANSLATOR
Text from laptop -> Morse via LED + buzzer
Button input -> Morse -> Text on Serial Monitor

Pins:
LED     = 13
Buzzer  = 12
Button  = 2
*/

const int ledPin = 13;
const int buzzerPin = 12;
const int buttonPin = 2;

// Morse timing
const int dotTime = 200;
const int dashTime = 600;
const int gapTime = 200;
const int letterGap = 600;
const int wordGap = 1400;

// Button timing
const int pressThreshold = 400; // short < 400ms = dot
String currentMorse = "";

unsigned long pressStart = 0;
bool lastButtonState = LOW;

// Morse table
char letters[] = {
  'A','B','C','D','E','F','G','H','I','J',
  'K','L','M','N','O','P','Q','R','S','T',
  'U','V','W','X','Y','Z'
};

String morseCodes[] = {
  ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
  "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
  "..-","...-",".--","-..-","-.--","--.."
};

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);

  Serial.println("=== Hybrid Morse Code Translator ===");
  Serial.println("Type text and press Enter");
  Serial.println("Short button press = dot");
  Serial.println("Long button press = dash");
}

void loop() {
  checkSerialInput();
  checkButtonInput();
}

/*
========================
TEXT -> MORSE
========================
*/

void checkSerialInput() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.toUpperCase();

    Serial.print("Input: ");
    Serial.println(input);

    for (int i = 0; i < input.length(); i++) {
      char c = input[i];

      if (c == ' ') {
        delay(wordGap);
        continue;
      }

      String morse = getMorse(c);

      if (morse != "") {
        Serial.print(c);
        Serial.print(" -> ");
        Serial.println(morse);

        playMorse(morse);
        delay(letterGap);
      }
    }

    Serial.println("Done.\n");
  }
}

String getMorse(char c) {
  for (int i = 0; i < 26; i++) {
    if (letters[i] == c) {
      return morseCodes[i];
    }
  }
  return "";
}

void playMorse(String code) {
  for (int i = 0; i < code.length(); i++) {
    if (code[i] == '.') {
      signal(dotTime);
    }
    else if (code[i] == '-') {
      signal(dashTime);
    }

    delay(gapTime);
  }
}

void signal(int duration) {
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);

  delay(duration);

  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

/*
========================
BUTTON -> TEXT
========================
*/

void checkButtonInput() {
  bool buttonState = digitalRead(buttonPin);

  // Button pressed
  if (buttonState == HIGH && lastButtonState == LOW) {
    pressStart = millis();
  }

  // Button released
  if (buttonState == LOW && lastButtonState == HIGH) {
    unsigned long pressDuration = millis() - pressStart;

    if (pressDuration < pressThreshold) {
      currentMorse += ".";
      Serial.print(".");
    } else {
      currentMorse += "-";
      Serial.print("-");
    }

    delay(800); // wait briefly for next input

    char decoded = decodeMorse(currentMorse);

    if (decoded != '?') {
      Serial.print(" -> ");
      Serial.println(decoded);
      currentMorse = "";
    }
  }

  lastButtonState = buttonState;
}

char decodeMorse(String code) {
  for (int i = 0; i < 26; i++) {
    if (morseCodes[i] == code) {
      return letters[i];
    }
  }
  return '?';
}