const int sensorPin = 1; // Digital pin connected to the sensor
const int ledPin = 13;   // Built-in LED for indication
const int detectionThreshold = 300; // Adjust this threshold based on your sensor's characteristics

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(sensorPin);

  if (sensorValue == HIGH) {
    digitalWrite(ledPin, HIGH); // Turn on the LED as an indication
    Serial.println("Object detected: Yes");
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED
    Serial.println("Object not detected: No");
  }

  delay(100);  // Add a small delay for stability
}