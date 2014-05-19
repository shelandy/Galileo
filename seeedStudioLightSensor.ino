/*
 Grove - Light Sensor demo v1.0
 
 signal wire to A0.
 By: Shelandy Ting
 origin: http://www.seeedstudio.com/wiki/Grove_-_Light_Sensor
*/
#include <math.h>
const int ledPin=12;                 //Connect the LED Grove module to Pin12, Digital 12
const int thresholdvalue=10;         //The treshold for which the LED should turn on. 
float Rsensor; //Resistance of sensor in K
void setup() {
  Serial.begin(9600);                //Start the Serial connection
  pinMode(ledPin,OUTPUT);            //Set the LED on Digital 12 as an OUTPUT
}
void loop() {
  int sensorValue = analogRead(0); 
  Rsensor=(float)(1023-sensorValue)*10/sensorValue;
  if(Rsensor>thresholdvalue)
  {
    digitalWrite(ledPin,HIGH);
  }
  else
  {
  digitalWrite(ledPin,LOW);
  }
//  Serial.println("the analog read data is ");
  Serial.println("analog read data:");
  Serial.println(sensorValue);  
//  Serial.println("the sensor resistance is ");
//  Serial.println(Rsensor,DEC);//show the ligth intensity on the serial monitor;
  delay(1000);
}

