// Definiciones de las funciones miembro.

#include <iostream>
using namespace std;

#include "DefinicionRectangulo.h"

Rectangulo::Rectangulo(double l, double a)
{
  AsignarDatos( l, a ); 
}

void Rectangulo::AsignarDatos( double l, double a)
{
  largo = l;
  ancho = a;
}

void Rectangulo::AsignarLargo(double l)
{
  largo = l;
}

void Rectangulo::AsignarAncho(double a)
{
  ancho = a;
}

double Rectangulo::ObtenerLargo()
{
  return largo;
}

double Rectangulo::ObtenerAncho()
{
  return ancho;
}

double Rectangulo::Area()
{
  return largo*ancho; 
}

double Rectangulo::Perimetro()
{
  return 2*(largo + ancho);
}

void Rectangulo::MostrarDatos()
{
  cout << "Este programa calcula el area y el perimetro de un rectangulo." << endl;
  cout << "Por favor ingrese el largo: ";
  cin >> largo;
  cout << "Por favor ingrese el ancho: ";
  cin >> ancho;
  cout << "El area del rectangulo es: " << Area() << endl;
  cout << "El perimetro del rectangulo es: " << Perimetro() << endl;
  
}



