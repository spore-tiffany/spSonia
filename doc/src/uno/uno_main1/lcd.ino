
unsigned long lcdBeginTime = 0;
unsigned long duration = 5000;
bool lightUp = false;

void lcdAlert(int count, int duration)
{
  for(int i = 0 ; i < count ; i++)
  {
    lcd.noBacklight();
    delay(duration);
    lcd.backlight();
    delay(duration);
  }

}
void lcdSetup() {
                    // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Beetle Room");
  lcd.setCursor(0,1);
  lcd.print("2025");
  lcd.setCursor(5,1);
  lcd.print("Enjoy coding");
  
  lcdAlert(3,200);

  lcdBeginTime = millis();
  lightUp = true;
}

  

void lcdLoop() {
  if(lightUp == true)
  {
    if(millis() - lcdBeginTime > duration)
    {
        lcdBeginTime = millis();
        lightUp = false;
        lcd.noBacklight();
    }
  }   
}
