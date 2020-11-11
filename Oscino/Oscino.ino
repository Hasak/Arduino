const int vpin=5;
//const int rpin=A3;
void setup() {
  pinMode(vpin,OUTPUT);
//  pinMode(rpin,INPUT);
//  Serial.begin(9600);
}

void loop() {
//  int an=analogRead(rpin);
//  int mp=map(an,0,1023,0,255);
//  Serial.println(an);
//  Serial.println(mp);
//  Serial.println();
//  analogWrite(vpin,mp);
  digitalWrite(vpin,1);
  delayMicroseconds(1);
  digitalWrite(vpin,0);
  delayMicroseconds(1);
}
