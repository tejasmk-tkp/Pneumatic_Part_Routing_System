//Limit Switches
const int L0 = 8;
const int L1 = 9;
const int L2 = 10;
const int L3 = 11;
const int L4 = A0;
const int L5 = A1;

//Object Sensor
const int IR = 12;

//Solenoid Pins
const int S0 = 2;
const int S1 = 3;
const int S2 = 4;
const int S3 = 5;
const int S4 = 6;
const int S5 = 7;

void setup() {

  pinMode(L0, INPUT);
  pinMode(L1, INPUT);
  pinMode(L2, INPUT);
  pinMode(L3, INPUT);
  pinMode(L4, INPUT);
  pinMode(L5, INPUT);

  pinMode(IR, INPUT);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);
  pinMode(S5, OUTPUT);

  digitalWrite(S0, LOW);
  digitalWrite(S1, LOW);
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  digitalWrite(S4, LOW);
  digitalWrite(S5, LOW);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available()){ //&& digitalRead(IR)==LOW) {
    //Actuate A
    digitalWrite(S0, HIGH);
    //Actuate B
    if (digitalRead(L1)==HIGH) {
      delay(1000);
      digitalWrite(S3, HIGH);
    }
    //Actuate C
    if (digitalRead(L3)==LOW) {
      delay(1000);
      digitalWrite(S5, HIGH);
    }
    //Retract A
    if (analogRead(L5)<50 && digitalRead(IR)==HIGH) {
      delay(1000);
      digitalWrite(S0, LOW);
      digitalWrite(S1, HIGH);
    }
    //Retract B
    if (digitalRead(L0)==HIGH) {
      delay(1000);
      digitalWrite(S3, LOW);
      digitalWrite(S2, HIGH);
    }
    //Retract C
    if (digitalRead(L2)==HIGH) {
      delay(1000);
      digitalWrite(S5, LOW);
      digitalWrite(S4, HIGH);
    }
    if (analogRead(L4)<50) {
      delay(1000);
      digitalWrite(S1, LOW);
      digitalWrite(S2, LOW);
      digitalWrite(S4, LOW);
    }
  }
}