#include <Arduino.h>

// Order: red, green, yellow, blue.
const byte LED_PINS[4] = {9, 10, 11, 12};
const byte BUTTON_PINS[5] = {7, 6, 5, 4, 3};
const byte BUZZER_PIN = 8;

// HIGH: buttons with external pull-down resistors.
// LOW: buttons connected to GND, using INPUT_PULLUP.
const byte PRESSED = HIGH;

// Fixed notes: red C4, green E4, yellow G4, blue C5.
const unsigned int COLOR_NOTES[4] = {262, 330, 392, 523};

const byte MAX_LEVEL = 100;
const unsigned long TIMEOUT_MS = 5000UL;
const unsigned long DEBOUNCE_MS = 30UL;

byte sequence[MAX_LEVEL];
byte stableState[5];
byte lastRawState[5];
unsigned long lastChange[5];

void allLedsOff() {
  for (byte i = 0; i < 4; i++) {
    digitalWrite(LED_PINS[i], LOW);
  }
}

void resetDebouncers() {
  unsigned long now = millis();

  for (byte i = 0; i < 5; i++) {
    byte state = digitalRead(BUTTON_PINS[i]);
    stableState[i] = state;
    lastRawState[i] = state;
    lastChange[i] = now;
  }
}

bool newPress(byte index) {
  byte raw = digitalRead(BUTTON_PINS[index]);
  unsigned long now = millis();

  if (raw != lastRawState[index]) {
    lastRawState[index] = raw;
    lastChange[index] = now;
  }

  if (raw != stableState[index] &&
      now - lastChange[index] >= DEBOUNCE_MS) {
    stableState[index] = raw;
    return raw == PRESSED;
  }

  return false;
}

void playColor(byte color, unsigned int durationMs) {
  digitalWrite(LED_PINS[color], HIGH);
  tone(BUZZER_PIN, COLOR_NOTES[color]);

  delay(durationMs);

  noTone(BUZZER_PIN);
  digitalWrite(LED_PINS[color], LOW);
}

void startupJingle() {
  for (byte color = 0; color < 4; color++) {
    playColor(color, 180);
    delay(90);
  }
}

void successSound() {
  tone(BUZZER_PIN, 784);
  delay(90);

  tone(BUZZER_PIN, 1047);
  delay(140);

  noTone(BUZZER_PIN);
  delay(250);
}

void defeatSound() {
  allLedsOff();

  for (int frequency = 800; frequency >= 120; frequency -= 20) {
    tone(BUZZER_PIN, frequency);
    delay(22);
  }

  noTone(BUZZER_PIN);

  for (byte flash = 0; flash < 3; flash++) {
    for (byte color = 0; color < 4; color++) {
      digitalWrite(LED_PINS[color], HIGH);
    }

    delay(130);
    allLedsOff();
    delay(130);
  }
}

void victorySound() {
  const unsigned int notes[8] = {
    523, 659, 784, 1047, 784, 1047, 1319, 1568
  };

  for (byte i = 0; i < 8; i++) {
    digitalWrite(LED_PINS[i % 4], HIGH);
    tone(BUZZER_PIN, notes[i]);

    delay(i == 7 ? 450 : 140);

    noTone(BUZZER_PIN);
    allLedsOff();
    delay(65);
  }
}

void showSequence(byte level) {
  delay(450);

  for (byte position = 0; position < level; position++) {
    playColor(sequence[position], 280);
    delay(170);
  }
}

int waitForColorPress() {
  unsigned long startedAt = millis();

  while (millis() - startedAt < TIMEOUT_MS) {
    for (byte color = 0; color < 4; color++) {
      if (newPress(color)) {
        return color;
      }
    }

    delay(2);
  }

  return -1;
}

void waitForStart() {
  resetDebouncers();

  byte chase = 0;
  unsigned long lastMove = millis();

  allLedsOff();
  digitalWrite(LED_PINS[chase], HIGH);

  while (true) {
    if (newPress(4)) {
      allLedsOff();
      return;
    }

    if (millis() - lastMove >= 140UL) {
      lastMove = millis();
      allLedsOff();

      chase = (chase + 1) % 4;
      digitalWrite(LED_PINS[chase], HIGH);
    }

    delay(2);
  }
}

void playGame() {
  randomSeed((unsigned long)analogRead(A0) ^ micros());

  for (byte level = 1; level <= MAX_LEVEL; level++) {
    sequence[level - 1] = (byte)random(4);

    showSequence(level);
    resetDebouncers();

    for (byte position = 0; position < level; position++) {
      int color = waitForColorPress();

      if (color < 0) {
        defeatSound();
        return;
      }

      playColor((byte)color, 180);

      if ((byte)color != sequence[position]) {
        defeatSound();
        return;
      }
    }

    if (level == MAX_LEVEL) {
      victorySound();
      return;
    }

    successSound();
  }
}

void setup() {
  for (byte color = 0; color < 4; color++) {
    pinMode(LED_PINS[color], OUTPUT);
    digitalWrite(LED_PINS[color], LOW);
  }

  for (byte i = 0; i < 5; i++) {
    pinMode(
      BUTTON_PINS[i],
      PRESSED == LOW ? INPUT_PULLUP : INPUT
    );
  }

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(A0, INPUT);

  randomSeed(analogRead(A0));
  resetDebouncers();
  startupJingle();
}

void loop() {
  waitForStart();
  playGame();
}
