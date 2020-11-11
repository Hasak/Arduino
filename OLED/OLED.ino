#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// OLED display TWI address
#define OLED_ADDR   0x3C

Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup() {
  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();
  // display a pixel in each corner of the screen
  /*display.drawPixel(0, 0, WHITE);
  display.drawPixel(127, 0, WHITE);
  display.drawPixel(0, 63, WHITE);
  display.drawPixel(127, 63, WHITE);*/

  // display a line of text
  //display.setTextSize(1);
  display.setTextColor(WHITE);
  //display.setCursor(27,30);
}

double V,I,P,E=0,t=500,v;
void loop() {
  // put your main code here, to run repeatedly:
  V=random(1000)/pow(10,random(4));
  I=random(100)/pow(10,random(3));
  P=V*I;
  E+=P*t/1000/4186000;
  v=random(40)/pow(10,random(3));
  display.setTextSize(1);
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("V = ");display.print(V);display.print(" V\nA = ");display.print(I);display.print(" A\nP = ");display.print(P);display.print(" W\nE = ");display.print(E);display.print(" kCal\n\n");
  display.setTextSize(2);
  //display.print("   ");
  display.print(v);display.print(" km/h");
  display.display();
  delay(t);
}
