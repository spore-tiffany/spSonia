int BTN_NONE = 0;
int BTN_PRESS = 1;
int BTN_RELEASE = 2;
int btnPin = 4;
int gState;
unsigned long nowTime;
void setup() {
  // put your setup code here, to run once:
  pinMode(btnPin , INPUT_PULLUP);
  Serial.begin(9600);
  gState = BTN_NONE;
}

void loop() {
  // put your main code here, to run repeatedly:
  int btnState = digitalRead(btnPin);
  if(btnState == false)
  {
     Serial.println("Press");
     if(gState == BTN_NONE)
     {
        gState = BTN_PRESS;
        nowTime = millis();
     }
  }
  else
  {
    Serial.println("No Press");
    if(gState == BTN_PRESS)
     {
        gState = BTN_RELEASE;
        //???????
        if(millis()-nowTime <1500)
        {
            Serial.println("short press");
        }
        else
        {
            Serial.println("long press");
        }
     }
     else if(gState == BTN_RELEASE)
     {
        gState = BTN_NONE;
     }
  }
  delay(500);
}
