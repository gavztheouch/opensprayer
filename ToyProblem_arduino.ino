#include <Encoder.h>
int value=0;
const byte sprayheads = 4;             // number of sprayheads
byte Spray[3];                        //an array to store spray solenoid postions

boolean newData = false;
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
  //Serial.println(newmyencoder);
  }
  
   


  
  
  if (Serial.available()) {
    Serial.read();
  recvWithEndMarker();
  showNewData();
  myencoder.write(0);
  }

  



  
  
}

//void count(){
  //encoder0Pos = encoder0Pos + 1;
//}

void recvWithEndMarker() {
    static byte ndx = 0;
    char endMarker = '7';
    char rc;
    
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (rc != endMarker) {
            Spray[ndx] = rc;
            ndx++;
            if (ndx >= sprayheads) {
                ndx = sprayheads - 1;
            }
        }
        else {
            Spray[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }

        
    }

    }
    

void showNewData() {

  int head = 0;         
  int heads = 4;
  int pinshift = 10;     //makes sure the correct pins are used, we are starting from 8
  int a = 0;

  while ( head < heads ){

    a = head + pinshift;
  
        //if (Spray[head] == '1')
        //digitalWrite (a, LOW);
        Serial.println(Spray[head]);
     
        //else if (Spray[head] == '0')
        //digitalWrite (a, HIGH);
        
        head++;
        
        
       }

        newData = false;
        
    }
