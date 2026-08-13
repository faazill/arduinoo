const int buzzerPin = 11;

// Notes
#define C4 262
#define D4 294
#define E4 330
#define F4 349
#define G4 392
#define A4 440
#define B4 494
#define C5 523
#define D5 587
#define E5 659

// Simplified melody
int melody[] = {
  E4, E4, E4,
  D4, E4, G4,
  G4, A4, G4,
  E4, D4, C4,

  E4, E4, E4,
  D4, E4, G4,
  G4, A4, B4,
  A4, G4, E4
};

// Note durations in milliseconds
int duration[] = {
  200, 200, 400,
  200, 200, 400,
  200, 200, 400,
  200, 200, 500,

  200, 200, 400,
  200, 200, 400,
  200, 200, 400,
  200, 200, 600
};

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  for (int i = 0; i < 24; i++) {

    tone(buzzerPin, melody[i], duration[i]);

    delay(duration[i] + 40);

    noTone(buzzerPin);
  }

  delay(1000);
}
