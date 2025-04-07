#include <SoftwareSerial.h>

#define rxPin 3
#define txPin 2

SoftwareSerial mySerial(rxPin, txPin);
void ledAlert(int count)
{
  for(int i =  0 ; i < count*2 ; i++)
  {
    digitalWrite(13, i%2);
    delay(50);
  }
}
void setup()  {
    // Define pin modes for TX and RX
    //pinMode(rxPin, INPUT);
    //pinMode(txPin, OUTPUT);
    pinMode(13, OUTPUT);
    // Set the baud rate for the SoftwareSerial object
    mySerial.begin(9600);
    
    Serial.begin(9600);
    Serial.println("setup");
    ledAlert(3);
}
String swSwrialReadCommand()
{
  String s="";
  while(mySerial.available())
  {
    char c = mySerial.read();
    if(c!='\n')
    {
      
      s+=c;
    }
    delay(5);
  }
  return s;

}
void loop() {
  String s = swSwrialReadCommand();
  if(s!="")
  {
    ledAlert(5);
    Serial.println(s);
  }
  delay(50);
    
}
