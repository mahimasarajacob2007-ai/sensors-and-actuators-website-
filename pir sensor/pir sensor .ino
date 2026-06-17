const int pirPin = 2;   // PIR Signal connected to D2
const int ledPin = 13;  // LED connected to D13

void setup() {
  pinMode(pirPin, INPUT);   // Sensor sends data IN
  pinMode(ledPin, OUTPUT);  // LED sends light OUT
}

void loop() {
  int motion = digitalRead(pirPin); // Read the sensor (1 = Motion, 0 = No Motion)

  if (motion == HIGH) {
    digitalWrite(ledPin, HIGH); // Turn LED on
  } else {
    digitalWrite(ledPin, LOW);  // Turn LED off
  }
}
