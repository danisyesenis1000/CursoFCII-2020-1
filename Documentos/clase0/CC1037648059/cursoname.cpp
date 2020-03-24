// Definiciones de funciones de miembro de LibroCalificar. Este archivo contiene
// Implementaciones de las funciones miembro prototipadas en LibroCalificar.h.
#include <iostream>
using namespace std;
#include<iomanip>
#include "Cursoname.h"
LibroCalificar::LibroCalificar( string name )
{
   setCourseName( name ); 
} 

void LibroCalificar::setCourseName( string name )
{
  if (name.length()<=25) courseName=name;
  if (name.length()>25)
    {
      courseName=name.substr(0,25);
      cout<<"Nombre \""<<name<<"\"" "excede la longitud máxima (25).\n"
     	  <<"Limitando el nombre del curso a los primeros 25 caracteres. \n"<<endl;
    }
} 
void LibroCalificar::asignarDatos()
{
  asignarLargo();
  asignarAncho();
}

void LibroCalificar::asignarLargo()
{
  double l;
  cout<<"Ingrese el Largo del cuadrado"<<endl;
  cin>>l;
  largo=l;
}
void LibroCalificar::asignarAncho()
{
  double a;
  cout<<"Ingrese el ancho del cuadrado"<<endl;
  cin>>a;
  ancho=a;
}
double LibroCalificar::area()
{
  double Area;
  Area=largo*ancho;
  return Area;
}

double LibroCalificar::perimetro()
{
  double Perimetro;
  Perimetro=2*largo+2*ancho;
  return Perimetro;
}

void LibroCalificar::mostrarDatos()
{
  cout<<"El Largo es "<<largo<<endl;
  cout<<"El ancho es "<<ancho<<endl;
  cout<<"El area es "<<area()<<endl;
  cout<<"El perimetro es "<<perimetro()<<endl;
}
















/*
  while(contadorCalif<=10)
  {
  cout<<"Escribe una Calificación: " ;
  cin>>calificacion;
  total=total+calificacion;
  contadorCalif=contadorCalif+1;
  }
  promedio=total/10;
  cout<<"\n El total de las 10 calificaciones es "<<total<<endl;
  cout<<"EL promedio de la clase es "<<promedio<<endl;
  } 
*/

