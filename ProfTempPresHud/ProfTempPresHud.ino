#include <Wire.h> 
#include <LiquidCrystal.h>
#include <OneWire.h> 
#include <DallasTemperature.h>
#include "cactus_io_BME280_I2C.h" 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

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
// Create BME280 object 
//BME280_I2C bme; // I2C using address 0x77 
  BME280_I2C bme(0x76); // I2C using address 0x76 

void setup() { 
  lcd.createChar(1, up);
  lcd.createChar(2, down);
  lcd.begin(16, 2);
  lcd.print("TEMP PRIT VLAGA");
  lcd.setCursor(0,1);
  lcd.print("  HASAK  2018");
  delay(3000);
  lcd.clear();

if (!bme.begin()) { 
lcd.print("Could not find a sensor!"); 
while (1); 
} 
bme.setTempCal(-1);// Temp was reading high so subtract 1 degree 

} 

void loop() { 

bme.readSensor(); 

lcd.print(" P = ");
lcd.print(bme.getPressure_HP()/1000,2);
lcd.print(" kPa");
lcd.setCursor(0,1);
lcd.print("T=");lcd.print(bme.getTemperature_C(),1);
lcd.print("\xDF");
lcd.print("C V=");
lcd.print(bme.getHumidity(),1);
lcd.print("%");

// Add a 2 second delay. 
delay(2000); //just here to slow down the output. 
}
