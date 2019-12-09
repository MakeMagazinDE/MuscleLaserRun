#include <Servo.h>

Servo myservo;
int LINKS = A3;
int L = 0;
int RECHTS = A2;
int R = 0;
int pos = 90;  //Position Laserservo

int thresholdL = 5; 
int thresholdR = 150;

void setup() {
Serial.begin(9600);
myservo.attach(9);}

void loop() {
L = analogRead(LINKS);
R = analogRead(RECHTS);

//Serial.println(L);
//Serial.println(R);

if ( L >= thresholdL && L>= R && pos <= 130){ // Linker Arm angespannt, rechter entspannt
  myservo.write(pos);
  delay(20);
  pos += 1;}
else if ( R >= thresholdR && R >= L && pos >= 70){
  myservo.write(pos);
  delay(20);
  pos -= 1;} // niedriger Wert bedeutet Laser zeigt nach rechts
}
