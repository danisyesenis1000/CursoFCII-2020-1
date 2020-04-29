#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

#include "DefinicionPunto1.h"



int main()
{
  double z0 = 0.0;
  double vz = 1.0;
  double R = 1.0;
  double w = 1.0;
  double t = 10.0;
  double dt = 0.1;
  int n = 10;;
  double alpha = M_PI;
  
  Espiral espiral(z0,vz,R,w,dt,t,n,alpha);

  espiral.Mostrar();

  return 0;
}
