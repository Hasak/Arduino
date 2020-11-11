#include <LiquidCrystal.h>
#include <OneWire.h> 
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 8 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);

byte up[] = {
  B00100,
  B01110,
  B11111,
  B01110,
  B01110,
  B01110,
  B01110,
  B00000
};

byte down[] = {
  B00000,
  B01110,
  B01110,
  B01110,
  B01110,
  B11111,
  B01110,
  B00100
};

void setup() {
  lcd.createChar(1, up);
  lcd.createChar(2, down);
  lcd.begin(16, 2);
  sensors.begin();
  lcd.print("  TEMPERATURA");
  lcd.setCursor(0,1);
  lcd.print("  HASAK  2017");
  delay(3000);
  lcd.clear();
  lcd.print("  TEMPERATURA");
}

  float tempe=-127;
 float tempt;
int last=-5;
void loop() {
  //lcd.clear();
  //lcd.setCursor(0,0);
  //lcd.print("  TEMPERATURA");
  lcd.setCursor(0,1);
  int t=millis()/1000;
  int h=t/3600;
  int m=(t%3600)/60;
  int s=(t%3600)%60;
  if(h<10)
  lcd.print("0");
  lcd.print(h);
  if(t%2==0){
    lcd.print(":");
  }
  else lcd.print(" ");
  if(m<10)
  lcd.print("0");
  lcd.print(m);
  if(t-last>=5)
  {
    last=t;
    sensors.requestTemperatures();
    tempt=sensors.getTempCByIndex(0);
    lcd.print("  ");
    if(tempe-tempt>=0.1 && tempe!=-127)
      lcd.write(2);
    else if(tempe-tempt<=-0.1 && tempe!=-127)
      lcd.write(1);
    else lcd.print(" ");
    lcd.print(" ");
    lcd.print(tempt,1);
    lcd.print("\xDF");
    lcd.print("C ");
    tempe=tempt;
  }
  delay(1);
}

