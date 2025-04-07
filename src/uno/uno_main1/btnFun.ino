int BTN_NONE = 0;
int BTN_PRESS = 1;
int BTN_RELEASE = 2;
int BTN_SHORT = 3;
int BTN_LONG = 4;

int btn1Pin = 8;
int btn2Pin = 9;
int btn3Pin = 10;
int gBtn1State,gBtn2State,gBtn3State;
unsigned long Btn1Time,Btn2Time,Btn3Time;

void btnSetup() {
  pinMode(btn1Pin , INPUT_PULLUP);
  pinMode(btn2Pin , INPUT_PULLUP);
  pinMode(btn3Pin , INPUT_PULLUP);
  Btn1Time = millis();
  Btn2Time = millis();
  Btn3Time = millis();
}

int getBtnState(int btnPin, int & btnState, unsigned long & nowTime) {
  // put your main code here, to run repeatedly:
  bool bBtnUP  = digitalRead(btnPin);
  if(bBtnUP == false)
  {
     //Serial.println("Press");
     if(btnState == BTN_NONE)
     {
        btnState = BTN_PRESS;
        nowTime = millis();
     }
  }
  else
  {
    //Serial.println("No Press");
    if(btnState == BTN_PRESS)
     {
        btnState = BTN_RELEASE;
        //???????
        if(millis()-nowTime <1500)
        {
            //Serial.println("short press");
            btnState = BTN_SHORT;
        }
        else
        {
            //Serial.println("long press");
            btnState = BTN_LONG;
        }
     }
     else if(btnState == BTN_SHORT || btnState == BTN_LONG )
     {
        btnState = BTN_NONE;
     }
  }
  return btnState;
}
void handleBtnCmd(int cmd)
{
  if(cmd == BTN_SHORT)
  {
    demoSenario++;
    demoSenario%=3;
    switch(demoSenario)
    {
    case 0:
      ledState = 0;
      LEDHangle(ledState);
    break;
    case 1:
      ledState =1 ;
      LEDHangle(ledState);
      break;
    case 2:
      ledState =2 ;
      LEDHangle(ledState);
      break;
    default:
    break;
    }
  }
  else if(cmd == BTN_LONG)
  {
    if(ledState == 0)
      ledState = 1;
    else
      ledState = 0;
    LEDHangle(ledState);

  }

}
void handleBtn()
{
  int btn1 = getBtnState(btn1Pin,gBtn1State,Btn1Time);
  int btn2 = getBtnState(btn2Pin,gBtn2State,Btn2Time);
  int btn3 = getBtnState(btn3Pin,gBtn3State,Btn3Time);
  /*
  Serial.print("btn1,btn2,btn3=");
  Serial.print(btn1);
  Serial.print(",");
  Serial.print(btn2);
  Serial.print(",");
  Serial.println(btn3);
  */
  if(btn1 !=  BTN_NONE && btn1 !=  BTN_PRESS)
  {
    handleBtnCmd(btn1);
  }
  if(btn2 !=  BTN_NONE && btn2 !=  BTN_PRESS)
  {
    sendCmd("/room2/UNO","btn",btn2);
  }
  if(btn3 !=  BTN_NONE && btn3 !=  BTN_PRESS)
  {
    sendCmd("/room3/UNO","btn",btn3);
  }
  
}