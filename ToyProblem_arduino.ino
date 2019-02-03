#include <Encoder.h>

int RPWM=5;
int LPWM=6;
// timer 0
int L_EN=7;
int R_EN=8;
//const byte interruptPin = 2;
//volatile unsigned int encoder0Pos = 0;
Encoder myencoder(2, 3);
long newmyencoder;


void setup() {
  
  //pinMode(interruptPin, INPUT_PULLUP);
  //attachInterrupt(digitalPinToInterrupt(interruptPin), count, RISING);
  
  
  // put your setup code here, to run once:
  for(int i=5;i<9;i++){
   pinMode(i,OUTPUT);
  }
   for(int i=5;i<9;i++){
   digitalWrite(i,LOW);
  }
   delay(1000);
    Serial.begin(9600);
  }
  


void loop() {
  // put your main code here, to run repeatedly:
  
  newmyencoder = myencoder.read();
  if (newmyencoder < 200) {
  
  digitalWrite(R_EN,HIGH);
  digitalWrite(L_EN,HIGH);

  analogWrite(RPWM,150);
   }

  if (newmyencoder >= 878) {
  
  analogWrite(RPWM,0);
  Serial.println(newmyencoder);
  }
  
   if (Serial.available()) {
    Serial.read();
    Serial.println("Reset both knobs to zero");
    myencoder.write(0);}
    

}

//void count(){
  //encoder0Pos = encoder0Pos + 1;
//}
