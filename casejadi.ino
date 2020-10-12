/*
 4 push signal and one relay module 4 relay with Remote

 Turns on and off 4 relays connected to digital
*/
// Read RF remote button codes using the RM4 library and send them over serial.
#include <rm4.h>

// Arduino pin connected to the receiver VCC in. Set this high to enable the
// receiver.
static const int kEnablePin = 2;

// Arduino pins connected to the data pins on the receiver.
static const int kData0Pin = 3;
static const int kData1Pin = 4;
static const int kData2Pin = 5;
static const int kData3Pin = 6;
const int relay1 =  14;             // the number of the relay1 pin
const int relay2 =  15;             // the number of the relay1 pin
const int relay3 =  16;             // the number of the relay1 pin
const int relay4 =  19;             // the number of the relay1 pin

int check = 0;
int count = 0;

// Create an RM4 object to read the button codes from the remote.
RM4 remote(kData0Pin, kData1Pin, kData2Pin, kData3Pin);

void setup() {
  // Initialize the serial interface.
  Serial.begin(9600);

  // Turn on the receiver.
  pinMode(kEnablePin, OUTPUT);
  digitalWrite(kEnablePin, HIGH);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}

void loop() {
  
        // Print the button code to the serial interface every 100 ms.
  const int button_code = remote.buttonCode();
    switch(button_code){

      
      case 4 :
       if(count > 100){
      digitalWrite(relay1, LOW);
      digitalWrite(relay4, LOW);
      check = 1;
      count = 100;
  }else if(count < 0){
    digitalWrite(relay1, HIGH);
    digitalWrite(relay4, HIGH);
    check = 0;
    count = 0;
  }
//  Serial.println(count);
  if(check == 0){
    count = count + 1;
    delay(20);
  }else if(check == 1){
    count = count - 1;

    delay(20);
  }

      
      break;
        case 1 :
        for(int i=1;i<=2;i++){
    digitalWrite(relay2, LOW);                    
    delay (200);                                                                         
    digitalWrite(relay2, HIGH); 
    delay (500);                    
    }                  

    
      break ;
      case 8 :
      digitalWrite(relay3, LOW);                    // remove 5v from pin 11 so relay in1 will be 0v and this make relay on
       delay (900);                                 // wait 1 second                                        
        digitalWrite(relay3, HIGH);                   // add 5v to arduino pin 11 so relay in1 will be 5v and this make relay off
  }
   
  Serial.println(button_code);
  
 // delay(100);
}
 
