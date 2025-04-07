#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
                    // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(5,0);
  lcd.print("holle");
  lcd.setCursor(5,1);
  lcd.print("jimmy");
   lcd.setCursor(0,2);
  lcd.print("Arduino LCM IIC 2004");
   lcd.setCursor(2,3);
  lcd.print("Power By Ec-yuan!");




}

  

void loop() {

}
