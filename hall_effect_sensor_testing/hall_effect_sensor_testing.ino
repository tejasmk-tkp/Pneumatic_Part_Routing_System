const int hallPin = A0;  // The digital pin connected to the Hall Effect sensor

void setup() {
  Serial.begin(9600);
  pinMode(hallPin, INPUT);  // Set the Hall Effect sensor pin as an input
}

void loop() {
  int sensorValue = analogRead(hallPin);  // Read the digital value from the Hall sensor
  
  // Serial.println(sensorValue);
    if (sensorValue <= 50) {
      Serial.println("Magnetic field detected!");  // If the sensor reads LOW, a magnetic field is detected
    } else {
     Serial.println("No magnetic field detected.");  // If the sensor reads HIGH, no magnetic field is detected
   }

  delay(100);  // Delay for 1 second before reading again
}