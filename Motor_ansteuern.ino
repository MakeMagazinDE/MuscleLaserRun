
#include "HCMotor.h" //Bibliothek zum steuern eines Motors
#define FAN 6 //IRF520 MOS Driver am digitalen PIN 6

HCMotor fan; 
void setup(){
  Serial.begin(9600);
  fan.Init();
  fan.attach(0, DCMOTOR, FAN);
  fan.DutyCycle(0, 100); //minimale 0 und maximale Geschwindigkeit 100
}
  
void loop(){
  //Wenn auf dem seriellen Eingang ein Wert anliegt dann....
  while(Serial.available() > 0){
  //Den Wert vom seriellen Eingang lesen und in einen Ganzzahligen Wert umwandeln.
  //Wenn nun ein Text eingegeben wird tritt hier ein Fehler auf. 
  //Der Code müsste also etwas robuster Programmiert werden.
  int value = Serial.readString().toInt();
  //Mappen der Werte, d.h. es wird der Wertebereich 0 bis 1024 auf 0 bis 100 transformiert.
  int fanSpeed = map(value, 0, 1024, 0, 100);
  fan.OnTime(0, fanSpeed); //Setzen der Geschwindigkeit am ersten Motor.
  }
  
}
