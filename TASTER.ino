#include <Servo.h>

Servo myservo;

int buttonApin = 7;
int buttonBpin = 8;
int pos = 90; 

byte leds = 0;

void setup() 
{
  Serial.begin(9600);
  myservo.attach(9); 
  
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);  
}

void loop() 
{
  while (digitalRead(buttonApin) == LOW && pos <= 130)
  {
      myservo.write(pos);              
      delay(20);                      
      pos += 1;
      }
       
 
  while (digitalRead(buttonBpin) == LOW && pos >= 70)
  {
      myservo.write(pos);             
      delay(20);                      
      pos -= 1;
      }
  Serial.println(pos);
  delay (50);
}
