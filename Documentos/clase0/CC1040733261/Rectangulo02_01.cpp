#include <iostream>
#include <string>
#include <cmath>
#include "Rectangulo.h"
using namespace std;

int main()
{
  // crea un objeto Rectangulo
 
  Rectangulo dRectangulo( double Largo, double Ancho);
  dRectangulo.asignarDatos();
  dRectangulo.obtenerLargo(); 
  dRectangulo.obtenerAncho();  
  dRectangulo.mostrarDatos();
  return 0; 
} 
