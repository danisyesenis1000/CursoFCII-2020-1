
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string> 
#include <vector>
using namespace std;

#include "clase.h"

int main()
{
  chess caballo;
  caballo.correriteracion();
  return 0;
}

/*
#include <iostream>
#include <iomanip>
#include <fstream>
using std::cout; 
using std::endl;

#include <string> 
using std::string;

#include "clase.h"

int main()
{
  int arregloCalificaciones[LibroCalificar::estudiantes][LibroCalificar::pruebas]={
    {87,96,70},
    {52,56,23},
    {52,12,48},
    {10,25,80},
    {20,10,0},
    {1,12,56},
    {45,48,65},
    {15,26,65},
    {45,21,45},
    {12,54,65}
  };    



  LibroCalificar gradeBook1( "Introduction to C++ Programmingcs101 INtroduccion al la programacion en c++",arregloCalificaciones );
  gradeBook1.mostrarMensaje();
  gradeBook1.procesarCalificaciones();
  return 0;

     
   
} 
*/
