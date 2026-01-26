int laser=13;
int ldr=12;
int buzzer=11;
int button=10;
#include<LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd (0x27,16,2);
bool alarmtrigger=false;

void setup() {
  // put your setup code here, to run once:
  pinMode(laser,OUTPUT);
  pinMode(ldr,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(button,INPUT_PULLUP);
 lcd.init();
lcd.backlight();
lcd.clear();

  digitalWrite(laser,HIGH);
  lcd.clear(); lcd.setCursor(0,0);
  lcd.print("SYSTEM READY");
  lcd.setCursor(0, 1);
  lcd.print("STATUS: SAFE");


}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonstate = digitalRead(button);

  int ldrvalue=digitalRead(ldr);
  if (ldrvalue==HIGH&&alarmtrigger==false){
    alarmtrigger=true;
    digitalWrite(buzzer,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("CODE RED       ");
    lcd.setCursor(0,1);
    lcd.print("ALERT          ");
  }
if(buttonstate==LOW&&alarmtrigger==true){
  alarmtrigger=false;
  digitalWrite(buzzer,LOW);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SAFE");
 
  }

}
