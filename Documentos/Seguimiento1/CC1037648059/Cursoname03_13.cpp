// Demostración de la clase LibroCalificar después de separar
// su interfaz desde su implementación.

#include <iostream>
using namespace std;

#include "Cursoname.h" // NOTE: inclulle la definicion de la clase

int main()
{
  LibroCalificar miLibroCalificar("CS101 Programacion en C++");
  //  miLibroCalificar.displayMessage();
  //  miLibroCalificar.determinarPromedioClase();
  miLibroCalificar.asignarDatos();
  miLibroCalificar.mostrarDatos();
  return 0;
} 
