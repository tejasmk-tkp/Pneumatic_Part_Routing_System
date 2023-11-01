//Limit Switches
const int L1 = 0;
const int L2 = 1;
const int L3 = 2;
const int L4 = 3;
const int L5 = 4;
const int L6 = 5;

//Object Sensor
const int sensorPin = 6;

//Solenoid Pins
const int S1 = 7;
const int S2 = 8;
const int S3 = 9;
const int S4 = 10;
const int S5 = 11;
const int S6 = 12;

//Push Button
const int buttonPin = 13;

//Push Button Variables
int buttonState = LOW;  // Current state of the button
int lastButtonState = LOW;  // Previous state of the button
unsigned long lastDebounceTime = 0;  // Last time the button state changed
unsigned long debounceDelay = 50;  // Debounce delay in milliseconds

int currentSolenoid = S1;

void setup() {
  // put your setup code here, to run once:
  pinMode(L1, INPUT);
  pinMode(L2, INPUT);
  pinMode(L3, INPUT);
  pinMode(L4, INPUT);
  pinMode(L5, INPUT);
  pinMode(L6, INPUT);

  pinMode(sensorPin, INPUT);

  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);
  pinMode(S5, OUTPUT);
  pinMode(S6, OUTPUT);

  pinMode(buttonPin, INPUT);

  digitalWrite(S1, LOW);
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  digitalWrite(S4, LOW);
  digitalWrite(S5, LOW);
  digitalWrite(S6, LOW);
}

void loop() {
  // Read the button state
  int reading = digitalRead(buttonPin);
  int sensorReading = digitalRead(sensorPin);

  // Check if the button state has changed and debounce it
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  // Check if the button state has been stable for the debounce delay
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // If the button state has changed and is HIGH (pressed), and the sensor input is LOW, execute your code
    if (reading == HIGH && buttonState == LOW && sensorReading == LOW) {
      // Your code to run once when the button is pressed and the sensor input is low
      digitalWrite(S1, HIGH);
      if (digitalRead(L2) == HIGH) {
        digitalWrite(S3, HIGH);
      }
      if (digitalRead(L4) == HIGH) {
        digitalWrite(S5, HIGH);
      }
      if (digitalRead(L6) == HIGH) {
        digitalWrite(S5, LOW);
        digitalWrite(S6, HIGH);
      }
      if (digitalRead(L5) == HIGH) {
        digitalWrite(S3, LOW);
        digitalWrite(S4, HIGH);
      }
      if (digitalRead(L3) == HIGH) {
        digitalWrite(S1, LOW);
        digitalWrite(S2, HIGH);
      }

      // Remember the button state
      buttonState = HIGH;
    } else if (reading == LOW && buttonState == HIGH) {
      // Reset the button state when the button is released
      buttonState = LOW;
    }
  }

  // Store the current button state for the next iteration
  lastButtonState = reading;
}