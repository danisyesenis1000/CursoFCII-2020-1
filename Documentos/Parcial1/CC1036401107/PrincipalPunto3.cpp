#include <iostream>

using namespace std;

#include "DefinicionPunto3.h"

int main()   //Funcion principal
{
  double ParteReal1;
  double ParteImaginaria1;
  double ParteReal2;
  double ParteImaginaria2;

  Complejo complejo(ParteReal1, ParteImaginaria1, ParteReal2, ParteImaginaria2);  //Creo el objeto de la clase
  complejo.AsignarParteReal(ParteReal1, ParteReal2);                             // Llamo a las funciones para que se ejecuten.
  complejo.AsignarParteImaginaria(ParteImaginaria1, ParteImaginaria2);
  complejo.MostrarDatos();
  complejo.MostrarNumero1();
  complejo.MostrarNumero2();

  return 0;
}
