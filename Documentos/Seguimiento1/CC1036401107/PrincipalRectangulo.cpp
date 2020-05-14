#include <iostream>

using namespace std;

#include "DefinicionRectangulo.h"

int main()
{

  double largo;
  double ancho;
  Rectangulo rectangulo(largo, ancho);
  rectangulo.AsignarAncho(ancho);
  rectangulo.AsignarLargo(largo);
  rectangulo.MostrarDatos();

  return 0;
}
