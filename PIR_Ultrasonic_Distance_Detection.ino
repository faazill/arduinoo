const int pirPin = 2;

const int trigPin = 9;
const int echoPin = 10;

void setup() {
  pinMode(pirPin, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

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

  if (motion == HIGH) {
    Serial.print("Motion Detected | Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  } else {
    Serial.print("No Motion | Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(500);
}
