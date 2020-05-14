// Demostración de la clase Rectangulo después de separar
// su interfaz desde su implementación.

#include <iostream>
using namespace std;

#include "Rectangulo.h" // NOTE: inclulle la definicion de la clase

int main()
{
   Rectangulo rectangulo1( 12.75,13.99 );
   
   cout << "Rectangulo de largo: " << rectangulo1.getLargo() << ", ancho: " << rectangulo1.getAncho()
        << "\nsu area es: " << rectangulo1.getArea() << " y su perimetro es: " << rectangulo1.getPerimetro() 
      << endl;
   return 0; 
} 

