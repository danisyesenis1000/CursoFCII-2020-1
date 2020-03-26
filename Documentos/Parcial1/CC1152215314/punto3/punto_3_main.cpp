#include "punto_3.h"

int main()
{
  Complejo C;
  C.AsignarDatos1(3.2,4.9);
  C.AsignarDatos2(2.8,5.1);
  C.MostrarNumeros();
  C.MostrarParteReal();
  C.MostrarParteImg();
  C.SumaNumeros();
  C.RestaNumeros();           //Hace (numero1 - numero2)
  C.MultiplicaNumeros();
  return 0;
}
