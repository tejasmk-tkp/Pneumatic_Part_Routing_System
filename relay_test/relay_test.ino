// Define the pin to control the relay
const int relayPin = 7;

void setup() {
  // Initialize the relay pin as an OUTPUT
  pinMode(relayPin, OUTPUT);
}

void loop() {
  // Turn the relay on
  digitalWrite(relayPin, HIGH);
  delay(1000); // Wait for 1 second

  // Turn the relay off
  digitalWrite(relayPin, LOW);
  delay(1000); // Wait for 1 second
}