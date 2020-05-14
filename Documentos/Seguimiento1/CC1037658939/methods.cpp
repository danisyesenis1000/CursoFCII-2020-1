#include <iostream>
#include <iomanip>

using namespace std;

#include "rectangulo.h"

/*
 * methods.cpp
 * 
 * Methods for class Rectangulo.
 * Requires rectangulo.h
 * 
 * Carolina Herrera S.
 * 
 * */
 

Rectangulo::Rectangulo(){
  largo = 0;
  ancho = 0;
}


void Rectangulo::asignarDatos( double a, double l ){
  asignarAncho( a );
  asignarLargo( l );
}


void Rectangulo::asignarAncho( double a ){
  ancho = a;
}


void Rectangulo::asignarLargo( double l ){
  largo = l;
}


double Rectangulo::area(){
  return largo*ancho;
}


double Rectangulo::perimetro(){
  return 2*largo + 2*ancho;
}


void Rectangulo::mostrarDatos(){
  double per, are;
  
  per = perimetro();
  are = area();
  
  cout << setw(5) << " " << setiosflags(ios::left) << setw(15) << "Largo"
       << setw(15) << "Ancho" << setw(15) << "Área" << setw(15) << "Perímetro"
       << endl;
  
  cout << "   " << string(57, '-') << endl;
  
  cout << setw(5) << " " << setiosflags(ios::left | ios::showpoint) << fixed
       << setprecision(5) << setw(15) << largo << setw(15) << ancho 
       << setw(15) << are << setw(15) << per 
       << endl;
}


double Rectangulo::obtenerAncho(){
  return ancho;
}


double Rectangulo::obtenerLargo(){
  return largo;
}


