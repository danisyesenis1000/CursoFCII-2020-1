#include "complejo.h"

int main()
{
  double real1, imaginario1, real2, imaginario2;
  complejo C(real1, real2, imaginario1, imaginario2);
  C.ObtenerParteReal();
  C.ObtenerParteImaginaria();
  C.ImpresionDatos();

  return 0;
}
