int value=0;
const byte sprayheads = 4;             // number of sprayheads
byte Spray[4];                        //an array to store spray solenoid postions

boolean newData = false;


void setup() 
   { 
      Serial.begin(9600); 
      pinMode(8, OUTPUT);
      pinMode(9, OUTPUT);
      pinMode(10, OUTPUT);
      pinMode(11, OUTPUT);
      digitalWrite (8, HIGH);
      digitalWrite (9, HIGH);
      digitalWrite (10, HIGH);
      digitalWrite (11, HIGH);
      Serial.println("Connection established...");
   }
 
void loop() 
   {
     
      recvWithEndMarker();
      showNewData();
      
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
        }
    }
}


void showNewData() {

  int head = 0;         
  int heads = 4;
  int pinshift = 8;     //makes sure the correct pins are used, we are starting from 8
  int a = 0;

  while ( head < heads ){

    a = head + pinshift;
  
        if (Spray[head] == '1')
        digitalWrite (a, LOW);
       
     
        else if (Spray[head] == '0')
        digitalWrite (a, HIGH);
        
        head++;
        
        
       }

        newData = false;
        
    }

     
    
    
