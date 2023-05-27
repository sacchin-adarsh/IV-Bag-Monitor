#include "HX711.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);

HX711 scale(3, 2); //HX711 scale(6, 5);

float calibration_factor = -196590;
float units;
float ounces;

void setup()
{
  lcd.init();
  lcd.clear();         
  lcd.backlight(); 
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("Remove Weights...");
  delay(2000);
  //Serial.println("HX711 weighing");
  scale.set_scale(calibration_factor);
  scale.tare();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tare Done!");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Place the IV bag");
  delay(1000);
  
}

void loop()
{
 
  //Serial.print("Reading:");
  units = scale.get_units(),10;
  if (units < 0)
  {
    units = 0.00;
  }
 // ounces = units * 0.035274;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("IV Bag Reading");
  lcd.setCursor(0,1);
  lcd.print("Weight");
  lcd.setCursor(7,1);
  lcd.print(units);
  Serial.println(units);
  lcd.setCursor(12,1);
  lcd.print("Kg");
  //Serial.println(" grams");
  delay(2500);
}
