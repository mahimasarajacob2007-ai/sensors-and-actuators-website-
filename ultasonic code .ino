const int trigPin = 3;  // Trig connected to D3
const int echoPin = 4;  // Echo connected to D4
const int ledPin = 13;  // LED connected to D13

void setup() {
  pinMode(trigPin, OUTPUT); // Trig sends the sound wave OUT
  pinMode(echoPin, INPUT);  // Echo listens for the sound IN
  pinMode(ledPin, OUTPUT);  // LED outputs light
  Serial.begin(9600);       // Start the monitor to read distances
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send a 10-microsecond sound pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read how long the sound wave took to bounce back (in microseconds)
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  int distance = duration * 0.034 / 2;
  
  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // If an object is closer than 30 cm, turn on the LED
  if (distance < 30) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(100); 
}
