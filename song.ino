const int buzzerPin = 11;

// Notes
#define C4 262
#define D4 294
#define E4 330
#define F4 349
#define G4 392
#define A4 440

int melody[] = {
  C4, C4, G4, G4,
  A4, A4, G4,
  F4, F4, E4, E4,
  D4, D4, C4
};

int duration[] = {
  400, 400, 400, 400,
  400, 400, 800,
  400, 400, 400, 400,
  400, 400, 800
};

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  for (int i = 0; i < 14; i++) {

    tone(buzzerPin, melody[i], duration[i]);

    delay(duration[i] + 50);

    noTone(buzzerPin);
  }

  delay(1000);
}
