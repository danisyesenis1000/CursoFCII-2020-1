// Definiciones de funciones de miembro de LibroCalificar. Este archivo contiene
// Implementaciones de las funciones miembro prototipadas en LibroCalificar.h.
#include <iostream>
using namespace std;

#include "Cursoname.h"

LibroCalificar::LibroCalificar( string name )
{
   setCourseName( name ); 
} 

void LibroCalificar::setCourseName( string name )
{
   courseName = name; 
} 

string LibroCalificar::getCourseName()
{
   return courseName; 
} 

void LibroCalificar::displayMessage()
{
   cout << "Bienvendo al libro de calificaciones para\n" << getCourseName() 
      << "!" << endl;
}
