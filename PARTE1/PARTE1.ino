#include <LiquidCrystal.h>

LiquidCrystal ANGELLO(7, 6, 5, 4, 3, 2);

void setup()
{
ANGELLO.begin(16, 2); 
  
 ANGELLO.print("Angello Mansilla");
 ANGELLO.setCursor(0,1);
 ANGELLO.print("2022380");
}

void loop()
{
  
}
