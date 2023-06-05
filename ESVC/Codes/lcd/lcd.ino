#include<LiquidCrystal.h>

LiquidCrystal lcd(7,9,10,11,12,13);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
 lcd.setCursor(4,0);
 lcd.print("Divya");
 lcd.setCursor(2,1);
 lcd.print("Smile");
}
