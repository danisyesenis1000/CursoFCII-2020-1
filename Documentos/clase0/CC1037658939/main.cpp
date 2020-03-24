#include <iostream>
#include "rectangulo.h"

/*
 * main.cpp
 * 
 * Usage of class Rectangulo.
 * Requires methods.cpp and rectangulo.h
 * 
 * Carolina Herrera S.
 * 
 * */

int main(){
  Rectangulo rectangulo1;
  
  // Assign length and width to object
  rectangulo1.asignarDatos(3.5, 4.2);
  
  // Shows data of object:
  // length, width, area, perimeter
  rectangulo1.mostrarDatos();
  
  cout << endl;
  
  // Change width and show updated data
  rectangulo1.asignarAncho(2.854);
  rectangulo1.mostrarDatos();
  
  return 0;
}
