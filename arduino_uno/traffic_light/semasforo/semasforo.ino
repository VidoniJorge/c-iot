

int DEPLAY_RED = 1500;
int DEPLAY_YELLOW = 500;
int DEPLAY_GREEN = 1500;
int flag;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT); // red led
  pinMode(3, OUTPUT); // yellow led
  pinMode(4, OUTPUT); // green led
  flag = 2;
}

void loop() {
  int pin;
  int delayLed;
  // put your main code here, to run repeatedly:

  switch(flag){
    case 2: // check current flag red
      pin = 3; // set pin led yellow
      flag = 5; // set flag yellow_red
      delayLed = DEPLAY_YELLOW;
      break;
    
    case 4: // check current flag green
      pin = 3; // set pin led yellow
      flag = 6; // set flag yellow_green
      delayLed = DEPLAY_YELLOW;
      break;
    
    
    case 5: // check current flag yellow_red
      pin = 4; // set pin led green
      flag = 4; // set flag green
      delayLed = DEPLAY_GREEN;
      break;
    
    case 6: // check current flag yellow_green
      pin = 2; // set pin led red
      flag = 2; // set flag red
      delayLed = DEPLAY_RED;
      break;
    default:
      pin = 2;
  }
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  printf(pin);
  digitalWrite(pin,HIGH);
  delay(delayLed);
}
