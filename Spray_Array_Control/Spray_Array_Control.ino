#include <Encoder.h>
int value=0;
const byte sprayheads = 48;             // number of sprayheads
byte Spray[48];                        //an array to store spray solenoid postions
int dist = 0;
boolean newData = false;
boolean showNewDataB = false;
int rowshift = 0;
Encoder myencoder(2, 3);
long newmyencoder;
int temprowshift;

void setup() 
   { 
      Serial.begin(9600); 
      
      pinMode(4, OUTPUT);
      pinMode(5, OUTPUT);
      pinMode(6, OUTPUT);
      pinMode(7, OUTPUT);
      pinMode(8, OUTPUT);
      pinMode(9, OUTPUT);
      pinMode(10, OUTPUT);
      pinMode(11, OUTPUT);
      pinMode(12, OUTPUT);
      pinMode(13, OUTPUT);
      digitalWrite (4, HIGH);
      digitalWrite (5, HIGH);
      digitalWrite (6, HIGH);
      digitalWrite (7, HIGH);
      digitalWrite (8, HIGH);
      digitalWrite (9, HIGH);
      digitalWrite (10, HIGH);
      digitalWrite (11, LOW);
      digitalWrite (12, HIGH);
      digitalWrite (13, HIGH);
      
   }
 
void loop() 
   {
      
      newmyencoder = myencoder.read();
      temprowshift = map(newmyencoder, 0, 3000, 0, 6); //map value of encoder or pot to 0-5
      rowshift = temprowshift * 8;                     //multiply map value by 8 to get rowshift value
      //Serial.print(rowshift);
      if(newmyencoder >= 3000){
        myencoder.write(0);
        digitalWrite(11, LOW);
        
      }
      recvWithEndMarker();
      if (showNewDataB == true){
        showNewData();
      }
      if (rowshift >= 47) {
        rowshift = 0;
        digitalWrite(11, LOW);
        showNewDataB = false;
        resetspray();
        }
     
      delay(1000);

   }

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
            showNewDataB = true;
            analogWrite(11,100);
        }
    }
}


void showNewData() {

  int head = 0;         
  int heads = 6;
  int pinshift = 4;     //makes sure the correct pins are used, we are starting from 8
  int a = 0;
  int bito;

  while ( head < heads ){

    
    a = head + pinshift;
    bito = head + rowshift;
  
        if (Spray[bito] == '1')
        digitalWrite (a, LOW);
       
     
        else if (Spray[bito] == '0')
        digitalWrite (a, HIGH);
        
        head++;
        
        
       }
        if (rowshift>= 48);{
        newData = false;}
        
    }
void resetspray() {

    digitalWrite (4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite (6, HIGH);
    digitalWrite (7, HIGH);
    digitalWrite (8, HIGH);
    digitalWrite (9, HIGH);
    digitalWrite (10, HIGH);

}

   
