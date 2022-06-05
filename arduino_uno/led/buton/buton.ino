const int led = 13;
const int boton = 12;

void setup() {
  pinMode(boton, INPUT_PULLUP);
  pinMode(led, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( digitalRead(boton) == LOW) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW); 
  }
}
