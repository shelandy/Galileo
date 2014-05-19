  /*
modify  Thumb Joystick demo v1.0by:http://www.seeedstudio.com
 connec the module to A0&A1ng;
 */

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  //int sensorValue1 = analogRead(A0)-235;
  //int sensorValue2 = analogRead(A1)-238;
  int sensorValue1 = analogRead(A0)-235-73; // galileo
  int sensorValue2 = analogRead(A1)-238-67; // 
  Serial.print("The X and Y coordinate is:");
  Serial.print(sensorValue1, DEC);
  Serial.print(",");
  Serial.println(sensorValue2, DEC);
  Serial.println(" ");
  delay(200);
}
