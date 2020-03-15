#include <iostream>
using namespace std; //espacio de nombres
#include "declaracion.h"

int main() //funcion principal
{
  Rectangulo Rectangulo1; //instancio mi objeto llamado Rectangulo1
  
  Rectangulo1.asignarDatos(30,25); //ingresar primero largo y luego ancho
  Rectangulo1.asignarAncho(25);
  Rectangulo1.asignarLargo(30);
  Rectangulo1.area();
  Rectangulo1.perimetro();
  Rectangulo1.mostrarDatos(); 
  Rectangulo1.obtenerAncho();
  Rectangulo1.obtenerLargo();

  return 0;
}
