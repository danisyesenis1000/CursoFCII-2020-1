#include <iostream>
#include "clase1.h"
#include <cmath>

using namespace std; 
Circular::Circular(double a1,double a2,double a3,double b1,double b2,double b3,int num)
{
  establecerDatos(a1,a2,a3,b1,b2,b3,num);
}
void Circular::establecerDatos(double a1,double a2,double a3, double b1,double b2,double b3, int num)
{
  radio = a1;
  fase = a2;
  frecAngular = a3;
  tinicial = b1;
  tfinal = b2;
  tTotal = b3;
  n = num;
  
}
double Circular::xpos(double t)
{
  return radio*cos(frecAngular*t + fase);
}
double Circular::ypos(double t)
{
  return radio*sin(frecAngular*t + fase);
}/*
double retornartinicial(){
  return tinicial;
}
double retornartfinal()
{
  return tfinal;
}
double retornarttotal()
{
  return tTotal;

int retornarintervalo()
{
  return n;
}
 */

//void Circular::resultado(double array[],double (*temp)(double))
 void Circular::resultado(double array1[],double array2[])
{
  int j=0;
  
  for(double t=tinicial;t<tfinal;t=t+tTotal/n)
    {
      //array[j]=(*temp)(t);
      array1[j]=xpos(t);
      array2[j]=ypos(t);
      //cout<<setw(2)<<xdatos[j]<<setw(10)<<ydatos[j]<<endl;
      j=j+1;
    }
}


      
  
