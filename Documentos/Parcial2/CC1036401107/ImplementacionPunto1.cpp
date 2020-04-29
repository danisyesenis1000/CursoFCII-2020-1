#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

#include "DefinicionPunto1.h"

Circular::Circular(double Radio,double Fre,double det,double tiempo, int N, double fase )
{
  R = Radio;
  w = Fre;
  dt = det;
  t = tiempo;
  n = N;
  alpha = fase;
}

double Circular::xpos( double t)
{
  return R*cos(w*t + alpha);
}

double Circular::ypos( double t)
{
  return  R*sin(w*t + alpha);
}

Circular::~Circular(){}



Espiral::Espiral(double zi, double velz, double Radio, double Fre, double det, double tiempo, int N, double fase):Circular(Radio,Fre,det,tiempo,N,fase)
{
  z0 = zi;
  vz = velz;
}


double Espiral::Mov_z(double z0, double vz, double t)
{
  return z0 + vz*t;
}

void Espiral::Mostrar()
{
  double i = 0;
  cout << setw(20) << setiosflags(ios::showpoint) << 'x'
       << setw(20) << 'y' << setw(20) << 'z' << endl;
  
  while ( i <= t)
    {
      cout << setw(20) << Circular::xpos(i) << setw(20)
	   << Circular::ypos(i) << setw(20)
	   << Mov_z(z0, vz, i) << endl;

      i += dt;
    }
}

Espiral::~Espiral(){}
