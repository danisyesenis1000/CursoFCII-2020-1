#include <iostream> //importamos la librerias necesarias
#include <iomanip>
#include <math.h>
#include "Espiral.h"
const float PI=3.1415; // Se define la variable PI

//implemetacion
Circulo::Circulo(float r, float w,float t, float fa,float dt) // contructor de la clse circulo
{
  radio=r;  //radio
  frecuencia_angular=w; //frecuencia angular
  tiempo=t; // tiempo
  fase=fa; // fase
  n_it=t/dt; // numero de iteraciones
  delta_t=dt; // delta de tiempo

}

void Circulo::xpos() //funcion para posicion en x
{
  cout<<"========VALOR DE X=============\n"<<endl;
  cout<<fixed<<setprecision(2)<<"X=[";
  for(int i =0; i<=n_it; i = i + 1)
    {
      cout<<(radio*cos(frecuencia_angular*i*delta_t+fase));// calculo del valor x
      if (i<n_it)
	{
	  cout<<", ";
	}
    }
  cout<<"]\n"<<endl;
}


void Circulo::ypos() // funcion para posicion y
{
  cout<<"========VALOR DE Y=============\n"<<endl;
  cout<<fixed<<setprecision(2)<<"Y=[";
  for(int i =0; i<=n_it; i = i + 1)
    {
      cout<<(radio*sin(frecuencia_angular*i*delta_t+fase)); // calculo del valor de y
      if (i<n_it)
	{
	  cout<<", ";
	}
    }
  cout<<"]\n"<<endl;
}

Circulo::~Circulo() // destructor de la clase circulo
{
}

Espiral::Espiral(float r, float w,float t, float fa,float dt,float vo,float poz)// contructor de la clase espiral
{
  radio=r; //radio
  frecuencia_angular=w; //frecuencia angular
  tiempo=t; //tiempo
  fase=fa; //fase
  n_it=t/dt; // numero de itaciones
  delta_t=dt; //delta de tiempo
  z0=vo; //z inicial
  vz=poz; // velocidad en z
}

void Espiral::zpos() //  funcion de la posicion en z
{
  cout<<"========VALOR DE Z=============\n"<<endl;
  cout<<fixed<<setprecision(2)<<"Z=[";
  for(int i =0; i<=n_it; i = i + 1)
    {
      cout<<(z0+vz*delta_t*i); //calculo del valor de z
      if (i<n_it)
	{
	  cout<<", ";
	}
    }
  cout<<"]\n"<<endl;
}

Espiral::~Espiral() // destructor de la clase espiral
{
}
