int IN1 = 8;
int IN2= 9;
int IN3 = 10;
int IN4 = 11;
int demora = 15; // demora entre pasos, no debe ser menor a 10 ms.

int steps [4][4] =
{
   {1,1,0,0},
   {0,1,1,0},
   {0,0,1,1},
   {1,0,0,1}, 
};

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i< 512; i++) { // 512 *4 = 2048
    for(int j=0; j<4;j++){
      digitalWrite(IN1, steps[j][0]);
      digitalWrite(IN2, steps[j][1]);
      digitalWrite(IN3, steps[j][2]);
      digitalWrite(IN4, steps[j][3]);
      delay(demora);  
    }
  }
}
