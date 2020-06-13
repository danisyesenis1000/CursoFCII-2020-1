//Proyecto de:
//Santiago Andrés Pérez
//Bryan Pérez
//Juan José Ochoa 

#include<iostream>
#include<iomanip>
#include<cmath>
#include <fstream>
#include <cstdlib>

using namespace std;

double d2x(double t,double x,double v){
  double  alfa= 1;
  double beta= -1;
  double gama= 0.3;
  double delta= 0.2;
  double omega= 1;
  double dx = -alfa*x*x*x - beta*x- delta*v + gama*cos(omega*t);
  return dx;
}


double R4K(double t0, double x0, double v0, double h,double tf,double paso)
{
  string archivor4 = "datos.dat";
  ofstream archivo_r4;
  archivo_r4.open(archivor4.c_str());
  if (archivo_r4.fail()){
    cout <<"El archivo no se abrió exitosamente"<<endl;
    exit(1);
  }
  //Formato de los datos
  archivo_r4 << setiosflags(ios::fixed);
  
  double PI=3.14159265359;
  int N1=400;
  int S1=100;
  int P1=100;
  
  for(double tt=t0+paso*P1*S1;tt<=tf;tt=tt+paso){
    int n = (int)((tt - t0) / h);
    double k1x, k2x, k3x, k4x;
    double k1v, k2v, k3v, k4v;
    double t = tt;
    double x = x0;
    double v = v0;
    archivo_r4<<t<<"   ";
    for (int i = 1; i <= n; i=++i)
      {
	k1x = h * v;
	k1v = h * d2x(t, x, v);
	k2x = h * (v + (1/2)*k1v);
	k2v = h * d2x(t + 0.5*h, x + 0.5*k1x, v + 0.5*k1v);
	k3x = h * (v + 0.5*k2v);
	k3v = h * d2x(t + 0.5*h, x + 0.5*k2x, v + 0.5*k2v);
	k4x = h * (v + k3v);
	k4v = h * d2x(t + h, x + k3x, v + k3v);
	x = x + (1.0 / 6.0)*(k1x + 2 * k2x + 2 * k3x + k4x);
	v = v + (1.0 / 6.0)*(k1v + 2 * k2v + 2 * k3v + k4v);
	t = t + h;
      }
    if(x>PI){
      x=x-2*PI;
    }
    if(x<-PI){
      x=x+2*PI;
    }
    archivo_r4<<x<<"   ";
    archivo_r4<<v<<"\n";
  }
  archivo_r4.close();
}

int main()
{
  double PI=3.14159265359;
  double alfa= 1;
  double beta= -1;
  double gama= 0.3;
  double delta= 0.2;
  double omega= 1;
  int N=400;
  int S=100;
  int P=100;
  double t0p, x0p, v0p,h,tp,paso1;
  tp=N*2*PI/omega;
  t0p = 0;
  x0p = PI/6;
  v0p = 0.0;
  h = 0.01;
  paso1=2*PI/(omega*P);
  
  R4K(t0p, x0p, v0p, h, tp,paso1);
  return 0;
}


