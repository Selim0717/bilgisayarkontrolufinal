#include <LCD.h>r 00000000000000000r 0
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C  lcd(0x27,2,1,0,4,5,6,7);
const int TrigPin = 5;
const int EchoPin = 4;
int mesafe ;
int sure;

void setup()
{
  lcd.begin (16,2);
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
  Serial.begin(9600);
  pinMode(TrigPin , OUTPUT);
  pinMode(EchoPin , INPUT);
}
void loop()
{
  digitalWrite(TrigPin , HIGH);
  digitalWrite(TrigPin , LOW);
  sure = pulseIn (EchoPin , HIGH);
  mesafe = (sure / 2) / 28.5;

  lcd.home();
  lcd.print("Mesafe = ");
  lcd.print((float)mesafe,1);
  lcd.print(" cm ");
  }