#include <SoftwareSerial.h>

#define rxPin 4//-->uno 2
#define txPin 5//-->uno 3

SoftwareSerial mySerial(rxPin, txPin);

void setup()  {
    // Define pin modes for TX and RX
    pinMode(rxPin, INPUT);
    pinMode(txPin, OUTPUT);
    
    // Set the baud rate for the SoftwareSerial object
    mySerial.begin(9600);
    Serial.begin(9600);
}

void loop() {
  /*
    if (mySerial.available() > 0) {
        char c=mySerial.read();
        Serial.println(c);
    }
  */
  mySerial.println("esp8266 say:hello");
  delay(2000);
}
