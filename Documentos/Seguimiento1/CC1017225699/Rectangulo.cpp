// Definiciones de funciones de miembro de Rectangulo. Este archivo contiene
// Implementaciones de las funciones miembro prototipadas en Rectangulo.h.
#include <iostream>
using namespace std;

#include "Rectangulo.h"

Rectangulo::Rectangulo( double largo, double ancho )
{
    setLargo( largo );
    setAncho( ancho );
    setArea( largo, ancho);
    setPerimetro( largo, ancho);    
} 

void Rectangulo::setLargo( double largo )
{
   RecLargo = largo; 
} 

void Rectangulo::setAncho( double ancho )
{
   RecAncho = ancho; 
}

void Rectangulo::setArea( double largo, double ancho  )
{
   RecArea = largo*ancho; 
}

void Rectangulo::setPerimetro( double largo, double ancho  )
{
   RecPerimetro = 2*largo + 2*ancho; 
}

double  Rectangulo::getLargo()
{
   return RecLargo; 
} 

double  Rectangulo::getAncho()
{
   return RecAncho; 
}

double  Rectangulo::getArea()
{
   return RecArea; 
}

double  Rectangulo::getPerimetro()
{
   return RecPerimetro; 
}
void Rectangulo::displayMessage()
{
   cout << "A continuacion los datos para el Rectangulo\n" << getLargo() <<", "<< getAncho() 
      << "!" << endl;
}
