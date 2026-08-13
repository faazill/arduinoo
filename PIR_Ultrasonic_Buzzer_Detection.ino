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

  digitalWrite(trigPin, LOW);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);

  Serial.begin(9600);
}


float getDistance() {

  // Send ultrasonic trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Wait for echo, maximum 30 ms
  long duration = pulseIn(echoPin, HIGH, 30000);

  // No echo received
  if (duration == 0) {
    return -1;
  }

  // Distance in cm
  float distance = duration * 0.0343 / 2;

  return distance;
}


void loop() {

  // Check PIR first
  int motion = digitalRead(pirPin);


  if (motion == HIGH) {

    // Motion detected
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);

    Serial.println("Motion Detected");

    // NOW activate ultrasonic sensor
    float distance = getDistance();

    if (distance > 0 && distance < 400) {

      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");

    } else {

      Serial.println("Distance: No Echo");

    }

  } 
  else {

    // No motion
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);

    Serial.println("No Motion");

    // Ultrasonic sensor is NOT triggered
  }


  delay(500);
}
