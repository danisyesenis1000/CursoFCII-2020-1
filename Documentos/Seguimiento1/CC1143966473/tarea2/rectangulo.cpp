#include <iostream> //importamos las diferentes librerias
#include <string>
#include<cmath>
#include<iomanip>

#include "rectangulo.h" //importamos  la clase Rectangulo
using namespace std; 



Rectangulo::Rectangulo(double l, double a) //constructor
{
  asignarDatos(l,a);
  
}

void  Rectangulo::asignarDatos(double lar, double an ) // funcion de asignar datos
{
  largo=lar;
  ancho=an;
  
}

double Rectangulo::asignarAncho() // asignar ancho
{
  return ancho;
}

double Rectangulo::asignarLargo() //asignar largo
{
  return largo;
}
  
void Rectangulo::obtenerAncho() // obtener ancho
{
  cout<<"Ancho="<<fixed<<setprecision(2)<<asignarAncho()<<endl;
}

void Rectangulo::obtenerLargo() //obtener Largo
{
  cout<<"Largo="<<fixed<<setprecision(2)<<asignarLargo()<<endl;
}

double Rectangulo::area() // función para área
{
  return asignarAncho()*asignarLargo();
}

double Rectangulo::perimetro() //función para perimetro
{
  return 2*(asignarAncho()+asignarLargo());
}

void Rectangulo::mostrarDatos() // función para mostrar datos
{
  cout<<fixed<<setprecision(2)<<"Largo="<<asignarLargo()<<"\n"
      <<"Ancho="<<asignarAncho()<<"\n"
      <<"Area="<<area()<<"\n"
      <<"Perimetro="<<perimetro()<<endl;
  
}

