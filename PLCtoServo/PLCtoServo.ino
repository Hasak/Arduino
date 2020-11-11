#include <Servo.h>

const int plcprah = 2;
const int plcvoda = 3;
const int servoprah = 5;
const int servovoda = 6;

const int mnp=90;
const int mxp=140;
const int mnv=160;
const int mxv=180;

Servo prah;
Servo voda;

void setup() {
  // put your setup code here, to run once:
  // Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(plcprah,INPUT_PULLUP);
  pinMode(plcvoda,INPUT_PULLUP);
  prah.attach(servoprah);
  voda.attach(servovoda);
  digitalWrite(LED_BUILTIN,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int p,v,i;
  p=digitalRead(plcprah);
  v=digitalRead(plcvoda);
  //Serial.println("p = "+String(p)+"; v = "+String(v));
  //Serial.println(p);
  /*for(i=160;i<300;i++){
    prah.write(i);
    Serial.println(i);
    delay(200);
  }*/
  if(p)
    prah.write(mxp);
  else prah.write(mnp);
  if(v)
    voda.write(mxv);
  else voda.write(mnv);
  delay(50);
}
