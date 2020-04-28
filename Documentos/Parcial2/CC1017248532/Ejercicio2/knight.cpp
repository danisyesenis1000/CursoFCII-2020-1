#include "utils/knight.h"

Knight::Knight(){}

void Knight::InitPos(int xo, int yo){
  xpos = xo;
  ypos = yo;
}

void Knight::UpdatePos(int xnew, int ynew){
  xpos = xnew;
  ypos = ynew;
}

void Knight::PrintCurrentPos(){
  cout << "x: " << xpos << ", y: " << ypos << endl;
}

int Knight::GetXPos() { return xpos; }
int Knight::GetYPos() { return ypos; }
