
const int sensor1 = 2;
int sensor1State = 0;
const int pwm1 = 10;
const int pwm2 = 11;
const int motor1a = 3;
const int motor1b = 4;
const int motor2a = 5;
const int motor2b = 6;
const int boton1 = 7;

void derecho() {
  digitalWrite(motor1a,HIGH);
  digitalWrite(motor2a,HIGH);
  digitalWrite(motor1b,LOW);
  digitalWrite(motor2b,LOW);
}

void giroIzq() {
  digitalWrite(motor2a,HIGH);
  digitalWrite(motor1b,HIGH);
  digitalWrite(motor1a,LOW);
  digitalWrite(motor2b,LOW);
}


void giroDer() {
  digitalWrite(motor2a,LOW);
  digitalWrite(motor1b,LOW);
  digitalWrite(motor1a,HIGH);
  digitalWrite(motor2b,HIGH);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor1, INPUT);
  pinMode(boton1, INPUT);

  pinMode(motor1a, OUTPUT);
  pinMode(motor1b, OUTPUT);
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensor1State = digitalRead(sensor1);
  if(sensor1State == HIGH) {
    analogWrite(pwm1,125);
    analogWrite(pwm2,125);
    derecho();
  } else {
    analogWrite(pwm1,125);
    analogWrite(pwm2,125);
    giroIzq();
  }
}
