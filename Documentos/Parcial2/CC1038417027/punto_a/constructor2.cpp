#include "clase2.h"
#include "clase1.h"
#include <iostream>

using namespace std;

Expiral::Expiral(double a1,double a2,double a3,double b1,double b2,double b3,int num,double _velz,double _zInicial) : Circular(a1,a2,a3,b1,b2,b3,num)
{
  establecerDatos(_velz,_zInicial);
}
void Expiral::establecerDatos(double _velz,double _zInicial)
{
  velz=_velz;
  zInicial = _zInicial;
}
double Expiral::zpos(double t)
{
  return zInicial + velz*t;
}
void Expiral::resultado2(double array[])
{
  double tinicial= retornartinicial();
  double tfinal =retornartfinal();
  double tTotal =retornarttotal();
  int n=retornarintervalo();
  int j=0;
  for (double t=tinicial;t<tfinal;t=t+tTotal/n){
    array[j]=zpos(t);
    j=j+1;
  }
}

