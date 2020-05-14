//Implementamos la clase

#include <iostream>
using namespace std; 
#include <iomanip>
#include <cmath>
#include "T2.h" //importamos la clase Rectangulo

Rectangulo::Rectangulo(double l, double a)
{
	largo = l;
	ancho = a;
}
void Rectangulo::asignarDatos(double l, double a)
{
	largo = l;
	ancho = a;
	return;
}
double Rectangulo::asignarAncho(double a)
{
	ancho = a;
	return ancho;
}
double Rectangulo::asignarLargo(double l)
{
	largo = l;
	return largo;
}
float Rectangulo::area()
{
	float arearectangulo;
	arearectangulo = largo*ancho;
	return arearectangulo;
}
float Rectangulo::perimetro()
{
	float perimetrorectangulo;
	perimetrorectangulo = 2*largo+2*ancho;
	return perimetrorectangulo;
}
void Rectangulo::mostrarDatos()
{
	float perirec;
	float arearec;
	arearec = area();
	perirec = perimetro();
	cout << "Area rectangulo: " << arearec << endl;
	cout << "Perimetro rectangulo: " << perirec << endl;
	return;
}
void Rectangulo::obtenerAncho()
{
	cout << "Ancho rectangulo: " << asignarAncho(ancho) << endl;
	return;
}
void Rectangulo::obtenerLargo()
{
	cout << "Largo rectangulo: " << asignarLargo(largo) << endl;
	return;
}

