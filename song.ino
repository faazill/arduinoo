const int buzzerPin = 11;

// Approximate meme-style rhythm
#define LOW_NOTE 220
#define MID_NOTE 330
#define HIGH_NOTE 440

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  // "Modi"
  tone(buzzerPin, MID_NOTE, 180);
  delay(200);

  tone(buzzerPin, HIGH_NOTE, 250);
  delay(270);

  // "Modi"
  tone(buzzerPin, MID_NOTE, 180);
  delay(200);

  tone(buzzerPin, HIGH_NOTE, 250);
  delay(270);

  // "Modi"
  tone(buzzerPin, MID_NOTE, 180);
  delay(200);

  tone(buzzerPin, LOW_NOTE, 500);
  delay(550);

  noTone(buzzerPin);

  delay(1000);
}
