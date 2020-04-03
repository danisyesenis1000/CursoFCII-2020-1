// Definicion de las funciones miembro

#include <iostream>
using namespace std;

#include "DefinicionPunto3.h"

// Constructor

Complejo::Complejo(double a, double b, double c, double d)
{
  AsignarDatos(a, b, c, d);
}

void Complejo::AsignarDatos(double a, double b, double c, double d)
{
  ParteReal1 = a;
  ParteImaginaria1 = b;
  ParteReal2 = c;
  ParteImaginaria2 = d;
}

void Complejo::AsignarParteReal(double a, double c)
{
  ParteReal1 = a;
  ParteReal2 = c;
}

void Complejo::AsignarParteImaginaria(double b, double d)
{
  ParteImaginaria1 = b;
  ParteImaginaria2 = d;
}

double Complejo::ObtenerParteReal()
{
  return ParteReal1, ParteReal2;
}

double Complejo::ObtenerParteImaginaria()
{
  return ParteImaginaria1, ParteImaginaria2;
}

void Complejo::MostrarNumero1()  // Despliega un mensaje con la forma del numero complejo 1. 
{
  cout << "El primer número complejo es: " << ParteReal1 << "+ i(" << ParteImaginaria1 <<")" <<  endl;
}

void Complejo::MostrarNumero2()  // Despliega un mensaje con la forma del numero complejo 2.
{
  cout << "El segundo número complejo es: " << ParteReal2 << "+ i(" << ParteImaginaria2 << ")" <<  endl;
}

double Complejo::SumaReal()    // Suma las partes reales
{
  return ParteReal1 + ParteReal2;
}

double Complejo::SumaImaginaria()  // Suma las partes imaginarias
{
  return ParteImaginaria1 + ParteImaginaria2;
}

double Complejo::RestaReal()  // Resta las partes reales
{
  return ParteReal1 - ParteReal2;
}

double Complejo::RestaImaginaria()  // Resta las partes imaginarias
{
  return ParteImaginaria1 - ParteImaginaria2;
}

void Complejo::MostrarDatos()   // Pide los numeros complejos y muestra en pantalla los numeros y las operaciones.
{
  cout << "Este programa hace operaciones aritmeticas con números complejos. " << endl;
  cout << "Por favor ingrese la parte real del primer numero: ";
  cin >> ParteReal1;
  cout << "Por favor ingrese la parte imaginaria: ";
  cin >> ParteImaginaria1;
  cout << "Por favor ingrese la parte real del segundo número: ";
  cin >> ParteReal2;
  cout << "Por favor ingrese la parte imaginaraia: ";
  cin >> ParteImaginaria2;
  cout << "La suma es: " << SumaReal() << "+ i(" << SumaImaginaria() << ")" << endl;
  cout << "La resta es: " << RestaReal() << "+ i(" << RestaImaginaria() << ")" << endl;
}
