int value=0;
const byte sprayheads = 38;             // number of sprayheads
byte Spray[38];                        //an array to store spray solenoid postions
int dist = 0;
boolean newData = false;
int rowshift = 0;


void setup() 
   { 
      Serial.begin(9600); 
      pinMode(2, OUTPUT);
      pinMode(3, OUTPUT);
      pinMode(4, OUTPUT);
      pinMode(5, OUTPUT);
      pinMode(6, OUTPUT);
      digitalWrite (2, HIGH);
      digitalWrite (3, HIGH);
      digitalWrite (4, HIGH);
      digitalWrite (5, HIGH);
      digitalWrite (6, HIGH);
      
   }
 
void loop() 
   {
     
      recvWithEndMarker();
      showNewData();
      rowshift = rowshift + 8;
      if (rowshift >= 30) {
        rowshift = 0;}
     
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
        }
    }
}


void showNewData() {

  int head = 0;         
  int heads = 5;
  int pinshift = 2;     //makes sure the correct pins are used, we are starting from 8
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

        newData = false;
        
    }
void showNewData2() {

  int head = 0;         
  int heads = 6;
  int pinshift = 2;     //makes sure the correct pins are used, we are starting from 8
  int rowshift = 9;     //makes sure the array is indexing the correct row
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

        newData = true;
        
    }

     
    
    
