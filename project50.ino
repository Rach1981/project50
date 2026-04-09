// Project 50 – Creating an IR Remote Control Arduino
int receiverpin = 2;        // pin 1 of IR receiver to Arduino digital pin 2
#include <IRremote.h> 
IRrecv irrecv(receiverpin); // create instance of irrecv
decode_results results;

void setup()
{
  irrecv.enableIRIn();      // start the receiver
  for (int z = 3 ; z < 8 ; z++) // set up digital pins 
  {
    pinMode(z, OUTPUT);
  }
  
  Serial.begin(9600); 
  

}

 void translateIR() 
// takes action based on IR code received
// uses Samusung IR codes 
{
  switch(results.value)
  {
     case 0xE0E020DF:  pinOn(3); break; // 3
    case 0xE0E0A05F:  pinOn(4); break; // 4
    case 0xE0E010EF:  pinOn(5); break; // 5
    case 0xE0E050AF:  pinOn(6); break; // 6
    case 0xE0E0609F:  pinOn(7); break; // 7
  }
 }

 void pinOn(int pin) // turns on digital pin "pin" for 1 second
 {
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
 }

void loop() 
{
   if (irrecv.decode(&results))    // have we received an IR signal?
  {
    translateIR();
     for (int z = 0 ; z < 2 ; z++) // ignore the 2nd and 3rd repeated codes
    {
      irrecv.resume();            // receive the next value
    }
  }
 }






