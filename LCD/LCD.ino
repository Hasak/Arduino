#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
byte customChar1[] = {
  B00000,
  B00000,
  B00111,
  B01000,
  B10000,
  B10000,
  B10000,
  B01000
};
byte customChar2[] = {
  B00000,
  B00000,
  B00000,
  B10001,
  B01010,
  B00100,
  B00000,
  B00000
};
byte customChar3[] = {
  B00000,
  B00000,
  B11100,
  B00010,
  B00001,
  B00001,
  B00001,
  B00010
};
byte customChar4[] = {
  B00010,
  B00001,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte customChar5[] = {
  B00000,
  B00000,
  B00000,
  B10001,
  B01010,
  B00100,
  B00000,
  B00000
};
byte customChar6[] = {
  B01000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
void setup() {
  int offset=12;
  lcd.createChar(0, customChar1);
  lcd.createChar(1, customChar2);
  lcd.createChar(2, customChar3);
  lcd.createChar(3, customChar4);
  lcd.createChar(4, customChar5);
  lcd.createChar(5, customChar6);
  lcd.begin(16, 2);
  lcd.print("Viktoria");
  lcd.setCursor(offset,0);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.setCursor(0, 1);
  lcd.write("is the best");
  lcd.setCursor(offset, 1);
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.write(byte(5));
}
void loop() {
  delay(1);
}

