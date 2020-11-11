#include<Stepper.h>
Stepper a,b;
const int xmax=40,ymax=20,maxs=200;
int x0=0,y0=0;
int xs=40,ys=40;

bool ugranici(int x0, int x, int y0, int y){
  if(x0+x>xmax || x0+x<0 || y0+y>ymax || y0+y<0)
    return false;
  return true;
}

bool pomakni(int x, int y){
  if(ugranici(x0,x,y0,y)){
    ta=x*xs+y*ys; // 2*40+1*40=120 T  // -2*40+1*40=-40
    tb=x*xs-y*ys; // 2*40-1*40=40  T  // -2*40-1*40=-120
    if(abs(ta)>abs(tb)){
      a.setSpeed(maxs);
      b.setSpeed(abs(tb)*maxs/abs(ta));
    }
    else if(abs(ta)<abs(tb)){
      a.setSpeed(abs(ta)*maxs/abs(tb));
      b.setSpeed(maxs);
    }
    else{
      a.setSpeed(maxs);
      b.setSpeed(maxs);
    }
    a.step(ta);
    b.step(tb);
    return true;
  }
  return false;
}

void setup() {
  // put your setup code here, to run once:
  a.setSpeed(maxs);
  b.setSpeed(maxs);
}

int i=0;

void loop() {
  // put your main code here, to run repeatedly:

  int x,y;
  int xn[]={45,6,2,7,6,4}
  int yn[]={3,26,7,25,2,3};
  //xn=izfajlax();
  //yn=izfajlay();
  x=xn[i]-x0;
  y=yn[i]-y0;

  if(pomakni(x,y)){
    x0=x;
    y0=y;
  }
  i++;
}
