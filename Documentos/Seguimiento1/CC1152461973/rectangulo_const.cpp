#include <iostream>
using namespace std;
#include "claseRectangulo.h"


Rectangulo::Rectangulo(double largoinp, double anchoinp) //private
{
  cout<<"Escriba el largo de su rectangulo:";
  cin>> largoinp;
  cout<<"Escriba el ancho de su rectangulo:";
  cin>> anchoinp;

  largo=largoinp;
  ancho=anchoinp;	
}
void Rectangulo::AsignarDatos(double largo0, double ancho0)
{
  largo=largo0;
  ancho=ancho0;
}
void Rectangulo::AsignarAncho(double ancho0)
{
  ancho=ancho0;
}
void Rectangulo::AsignarLargo(double largo0)
{
  largo=largo0;
}
 double Rectangulo::area()
{
  return(largo*ancho);	
}
double Rectangulo::perimetro()
{
  return 2*(largo + ancho);	
}
void Rectangulo::ObtenerLargo()
{
  cout<<"El largo del rectangulo es: "<<largo<<endl;
}
void Rectangulo::ObtenerAncho()
{
  cout<<"El ancho del rectangulo es: "<<ancho<<endl;
}
void Rectangulo::MostrarDatos()
{
  cout<<"EL perimetro es: "<<perimetro()<<endl; 
  cout<<"El area es: "<<area()<<endl;
}

