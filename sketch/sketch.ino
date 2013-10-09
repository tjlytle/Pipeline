#include <SoftwareSerial.h>
 
SoftwareSerial gsm(7, 8);
int light = 0;
int temp  = 1;

void setup()
{
  gsm.begin(19200);
  Serial.begin(19200);
  delay(500);
  Serial.println('setup');
  
}
 
void loop()
{
  int lightData = analogRead(light);
  lightData = map(lightData, 300, 1000, 0, 255);
  lightData = constrain(lightData, 0, 255);
  Serial.println("light");
  Serial.println(lightData);
  

  int tempData = analogRead(temp);
  Serial.println("temp");
  Serial.println(tempData);

  
  //send data
  Serial.println("waiting");
  delay(10000);
  sendSMS(lightData, tempData);
  

  //echo modem output
  while(gsm.available()){
    Serial.write(gsm.read());
  }
}
 
void sendSMS(int light, int temp)
{
  gsm.print("AT+CMGF=1\r");
  delay(100);
  gsm.println("AT + CMGS = \"+NEXMO_NUMBER\"");
  delay(100);
  gsm.println(light);
  gsm.println(temp);
  delay(100);
  gsm.println((char)26);
  delay(100);
  gsm.println();
}