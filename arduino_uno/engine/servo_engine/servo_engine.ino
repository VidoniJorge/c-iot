#include<Servo.h>

int servo1 = 9;

Servo servo;

int angulo = 0;
int potPin = A0;
int potValue = 0;

void setup() {
  // put your setup code here, to run once:
  servo.attach(servo1); // Le asignamos al servo el pin 9
}

void loop() {
  // put your main code here, to run repeatedly:
  /*for ( angulo = 0; angulo < 180; angulo++) {
    servo.write(angulo);
    delay(30);
  }

    for ( angulo = 180; angulo > 0; angulo--) {
    servo.write(angulo);
    delay(30);
  }*/

  potValue = analogRead(potPin);
  angulo = map(potValue,0,700,0,180);
  delay(30);
  servo.write(angulo);
  
  
}
