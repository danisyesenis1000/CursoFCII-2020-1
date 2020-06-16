#include<iostream>
#include<string> // Importamos la librerias neeesarias
#include<cmath>
#include "complejo.h"
using namespace std;

int main() // inicio de funcion main
{
  double real=2; // se define el primero complejo
  double imaginario=3;
  Complejo c1(real,imaginario);
  
  double real1=20;
  double imaginario1=3;
  Complejo c2(real1,imaginario1); // se define el segundo complejo

  Complejo R;
  cout<<"===================="<<endl;
  c1.ImpresioNumeroComplejos(); // Se imprimen los valores del complejo1
  c2.ImpresioNumeroComplejos(); // se imprimen los valores del complejo2
  cout<<"===================="<<endl;
  // se llaman la sumarComplejos y RestarComplejos
  R.SumaNumerosComplejos(c1.obtenerParteReal(),c1.obtenerParteImaginaria(),c2.obtenerParteReal(),c2.obtenerParteImaginaria());
  R.RestaNumerosComplejos(c1.obtenerParteReal(),c1.obtenerParteImaginaria(),c2.obtenerParteReal(),c2.obtenerParteImaginaria());

  cout<<"===================="<<endl;
  return 0; // termina funcion main
}
