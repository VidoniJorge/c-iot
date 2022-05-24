int led = 3;
int potPin = A0;
int potValue = 0;

void setup() {
  pinMode(led, OUTPUT);

  Serial.begin(9600); // inicializa el la comunicación serial de arduino
}

void loop() {
  potValue = analogRead(potPin);

  Serial.println(potValue);
  
  digitalWrite(led, HIGH);
  delay(potValue);
  digitalWrite(led, LOW);
  delay(potValue);
}
