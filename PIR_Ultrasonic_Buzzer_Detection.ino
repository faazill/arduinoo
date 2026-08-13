const int pirPin = 2;

const int trigPin = 9;
const int echoPin = 10;

const int buzzerPin = 11;
const int ledPin = 12;

void setup() {
  pinMode(pirPin, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  float distance = duration * 0.0343 / 2;

  return distance;
}

void loop() {
  int motion = digitalRead(pirPin);
  float distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | ");

  if (motion == HIGH) {
    Serial.println("Motion Detected");

    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
  } 
  else {
    Serial.println("No Motion");

    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}
