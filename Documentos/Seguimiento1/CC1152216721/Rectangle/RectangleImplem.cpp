//Funciones miembro del archivo de encabezado "RectangleHeader.h"
//con implementaciones para obtener, calcular y mostrar informacion
//sobre un rectangulo

#include <iostream>
#include <iomanip>
#include <vector>
#include "RectangleHeader.h"

#define CUSTOMPRINT std::setw(4) << std::fixed << std::setprecision(2) <<

//Constructor
Rectangulo::Rectangulo()
{
  largo = 0.0;
  ancho = 0.0;
}

//Obtener el largo por entrada de usuario
void Rectangulo::obtenerLargo()
{
  std::cout << "Ingrese el largo del rectangulo, en unidades de longitud: " << std::endl;
  std::cin >> largo;
}

//Obtener el ancho por entrada de usuario
void Rectangulo::obtenerAncho()
{
  std::cout << "Ingrese el ancho del rectangulo, en unidades de longitud: " << std::endl;
  std::cin >> ancho;
}

//Asignar el valor de la variable interna "largo" y retornarla en la variable "Largo"
double Rectangulo::asignarLargo( double Largo )
{
  Largo = largo;
  return Largo;
}

//Asignar el valor de la variable interna "Ancho" y retornarla en la variable "Ancho"
double Rectangulo::asignarAncho( double Ancho )
{
  Ancho = ancho;
  return Ancho;
}

//Calcular el area del rectangulo y retornar el resultado en la variable "Area"
double Rectangulo::area()
{
  double Area;
  Area = largo * ancho;
  return Area;
}

//Calcular el perimetro del rectangulo y retornar el resultado en la variable "Perimetro"
double Rectangulo::perimetro()
{
  double Perimetro;
  Perimetro = 2.0 * (largo + ancho);
  return Perimetro;
}

//Asignar el area y perimetro como entradas del vector bidimensional "Datos"
std::vector<double> Rectangulo::asignarDatos( double Area, double Perimetro )
{
  std::vector<double> Datos{Area, Perimetro};
  return Datos;
}

//Mostrar los datos en pantalla
void Rectangulo::mostrarDatos( std::vector<double> Datos )
{
  double RecArea = Datos[0];
  double RecPerimetro = Datos[1];

  std::cout << "\nPara el rectangulo de dimensiones: " 
            << "\nlargo = " << CUSTOMPRINT largo << " unidades de longitud,"
            << "\nancho = " << CUSTOMPRINT ancho << " unidades de longitud,"
            << "\nEl area es igual a " << CUSTOMPRINT RecArea << " unidades de longitud al cuadrado," 
            << "\nEl perimetro es igual a " << CUSTOMPRINT RecPerimetro << " unidades de longitud." << std::endl;
}

