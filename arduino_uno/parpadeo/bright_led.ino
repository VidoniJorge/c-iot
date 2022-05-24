int led1 = 3;
int led2 = 5;
int led3 = 6;

int pot = A0;
int potValue = 0;
int brightValue = 0;

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(pot);
  brightValue = map(potValue, 0, 1023, 0, 255); // hace regla de tres para pasar los posibles valores del pot (0-1024) a 0-255, que es lo que soporta la salida de pwm de arduino
  analogWrite(led1, brightValue);
  delay(10);
}
