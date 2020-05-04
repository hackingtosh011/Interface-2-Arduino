//COM 5

int micromotor = 12;
int statemotor;
int microstart = 11;
int statestart;
int microstop = 10;
int statestop;

void setup() {
  Serial.begin(115200);
  
  pinMode(micromotor, INPUT);
  pinMode(microstart, INPUT);
  pinMode(microstop, INPUT);
}

void loop() {
  statemotor = digitalRead(micromotor);
  statestart = digitalRead(microstart);
  statestop = digitalRead(microstop);

  Serial.print(statemotor);
  Serial.print(",");
  Serial.print(statestart);
  Serial.print(",");
  Serial.println("0");

  delay(10);
}
