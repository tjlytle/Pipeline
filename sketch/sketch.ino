#include <SoftwareSerial.h>
 
SoftwareSerial gsm(7, 8);
int inputPin = 0;

void setup()
{
  gsm.begin(19200);
  Serial.begin(19200);
  delay(500);
  
  
}
 
void loop()
{
  int data = analogRead(inputPin);
  data = map(data, 300, 1000, 0, 255);
  data = constrain(data, 0, 255);
  
  //send data
  delay(5000);
  sendSMS(data);
  Serial.println(data);
  
  //echo modem output
  while(gsm.available()){
    Serial.write(gsm.read());
  }
}
 
void sendSMS(int data)
{
  gsm.print("AT+CMGF=1\r");
  delay(100);
  gsm.println("AT + CMGS = \"+1XXXXXXXXXX\"");
  delay(100);
  gsm.println(data);
  delay(100);
  gsm.println((char)26);
  delay(100);
  gsm.println();
}
