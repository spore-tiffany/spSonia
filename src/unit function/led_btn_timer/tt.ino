
#define BTN_NONE 0
#define BTN_PRESS 1
#define BTN_RELEASE 2
/*
int btnState;
void setup() {
  btnsetup();
  Serial.begin(9600);
  btnState = BTN_NONE;
}

void loop() {

}

String getBtnState()
{
  String rtn;
  bool btnFlag = btnloop();
  if(!btnFlag)//是-->按下
  {
    Serial.println("Yes");
    if(btnState == BTN_NONE)
    {
      btnState = BTN_PRESS;
    }
  }
  else {
    Serial.println("No");
    if(btnState == BTN_PRESS)
    {
      btnState = BTN_RELEASE;
    }
    else if(btnState == BTN_RELEASE)
    {
      btnState = BTN_NONE;
    }
  }
  


  return rtn;
}
*/
