#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "declaracion.h"

using namespace std;

complejo::complejo(double r, double i) //constructor
{
  parteReal=r;
  parteImaginaria=i;
}

void complejo::asignarDatos(double r, double i)
{
  parteReal=r;
  parteImaginaria=i;
}


double complejo::obtenerParteReal()
{
  return parteReal;
}

double complejo::obtenerParteImaginaria()
{
 
  return parteImaginaria ;
}

void complejo::Suma(double r1,double r2, double im1, double im2)
{
  double sumarre,sumarco;
  sumarre=r1+r2;
  sumarco=im1+im2;
  cout <<"suma de complejos " << sumarre  << "+" << sumarco <<"i" << endl;
}

void complejo::Resta(double r1,double r2, double im1, double im2)
{
  double restare,restaco;
  restare=r1-r2;
  restaco=im1-im2;
  cout << "resta de complejos " <<  restare  << "+" << restaco <<"i" << endl;  
}

void complejo::mostrarnumero()
{
  double Real;
  double Imaginario;
  Real=obtenerParteReal();
  Imaginario=obtenerParteImaginaria();
  cout << "numero complejo " << Real  << "+" << Imaginario <<"i" << endl;
}
