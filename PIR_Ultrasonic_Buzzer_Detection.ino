const int pirPin = 2;

const int trigPin = 9;
const int echoPin = 10;

const int buzzerPin = 11;

void setup() {
  pinMode(pirPin, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzerPin, OUTPUT);

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

    // Turn buzzer ON when motion is detected
    digitalWrite(buzzerPin, HIGH);
  } 
  else {
    Serial.print("No Motion | Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Turn buzzer OFF when no motion is detected
    digitalWrite(buzzerPin, LOW);
  }

  delay(500);
}
