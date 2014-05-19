//#include <Servo.h>

#define ECHOPIN	 7
#define TRIGGERPIN	 6
//#define ECHOPIN	 3 
//#define TRIGGERPIN	 2 
//#define ECHOPIN	 0
//#define TRIGGERPIN	 1
//#define TRIGGERPIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
//#define ECHOPIN     11  // Arduino pin tied to echo pin on

int max(int num1, int num2)
{
     if(num1 > num2)
     {
          return num1;
     }else{
          return num2;
     }
}

 
#define US_ROUNDTRIP_IN 146     
#define US_ROUNDTRIP_CM 57      
#define NewPingConvert(echoTime, conversionFactor) (max((echoTime + conversionFactor / 2) / conversionFactor, (echoTime ? 1 : 0)))

unsigned long pinStart;
unsigned long pinEnd;


void setup()
{
  Serial.begin(9600);
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
//  pinMode(TRIGGERPIN, OUTPUT_FAST);
//  pinMode(ECHOPIN, INPUT_FAST);
}

void loop()
{
  digitalWrite(TRIGGERPIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGERPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGERPIN,LOW);
  
  while(digitalRead(ECHOPIN)==LOW){}; //waiting for the pin to trigger
  pinStart = micros();
  while(digitalRead(ECHOPIN)==HIGH){};//waiting for the pin to go low
  pinEnd = micros();
  
  unsigned int echoTime = pinEnd - pinStart;
  Serial.print("distance=");
  Serial.println(NewPingConvert(echoTime, US_ROUNDTRIP_IN));
  delay(1000); 
}
