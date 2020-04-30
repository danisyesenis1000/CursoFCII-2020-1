#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

#include "CircularEspiral.h"

Circular::Circular(double r, double w, double dt1, int n_int, double a)
{
  radio = r;
  omega = w;
  dt = dt1;
  n_intervalos = n_int;
  alpha = a;
}

Circular::~Circular()
{
}

void Circular::datos()
{
    cout<<"El radio de la trayectoria es: "<< radio << endl;
    cout<<"La frecuencia angular es: "<< omega << endl;
    cout<<"La fase es: "<< alpha << endl;
    cout<<"Se obtendrá la posición del cuerpo cada "<< dt<< endl;
    cout<<"El número de intervalos temporales en que se ubicará el cuerpo es: "<<n_intervalos<<endl;
    cout<<"El tiempo total del movimiento es: "<<dt*n_intervalos<<endl;
}

double Circular::xpos()
{
  double X[n_intervalos];
  for(int i=0;i<=n_intervalos;i++){
    X[i]=radio*cos(omega*dt*i+alpha);
    cout<<"La posición en x para el tiempo t = "<<i*dt<< "s es: " <<X[i] <<endl;
  }
}

double Circular::ypos()
{
  double Y[n_intervalos]; //Se crea la lista del tamaño de la cantidad de intérvalos
  for(int i=0;i<=n_intervalos;i++){
    Y[i]=radio*sin(omega*dt*i+alpha); //Cada parte de la lista depende de i (intervalo)
    cout<<"La posición en y para el tiempo t = "<<i*dt<< "s es: " <<Y[i] <<endl;
  }
}

Espiral::Espiral(double r, double w, double dt1, int n_int, double a, double z, double vz) : Circular(r, w, dt1, n_int, a)
{
    z0 = z;
    vz0 = vz;
}
Espiral::~Espiral()
{
}

void Espiral::datosz()
{
    datos();
    cout<< "La posición inicial en z es: "<< z0 << endl;
    cout<< "La velocidad inicial en z es: "<< vz0 << endl;
}

double Espiral::zpos()
{
    xpos();
    ypos();
    double Z[n_intervalos];
    for(int i=0;i<=n_intervalos;i++){
        Z[i]= z0 + vz0*dt*i;
        cout<<"La posición en z para el tiempo t = "<<i*dt<< "s es: " <<Z[i] <<endl;
}
}
