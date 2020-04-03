#include <iostream> //importamos las diferentes librerias
#include <string>
#include<cmath>
#include<iomanip>

#include "complejo.h" //importamos  la clase complejo
using namespace std;


Complejo::Complejo(double R, double I) //constructor
{
  asignarDatos(R,I);
  
}

void Complejo::asignarDatos(double R, double I ) // funcion de asignar datos
{
  parteImaginaria=I;
  parteReal=R; 
}

double  Complejo::obtenerParteReal() // obtener parte real
{
  return parteReal;
}

double  Complejo::obtenerParteImaginaria() // asignar anchoobtener parte imaginara
{
  return parteImaginaria;
}

void Complejo::SumaNumerosComplejos(double a, double b, double c ,double d) // suma de nuemros
{
  cout <<"\nLa suma de los numeros es= "<<a+c
       << " + " <<b+d 
       <<"i" << endl;
}

void Complejo::RestaNumerosComplejos(double a, double b, double c ,double d) // resta de nuemros
{
  cout <<"La resta de los numeros es= "<<a-c
       << " + " <<b-d 
       <<"i" << endl;
  
}

void  Complejo::ImpresioNumeroComplejos() // imprimir numero complejo
{
  cout<<"Numero complejo es= "<<obtenerParteReal()<<" + "<<obtenerParteImaginaria()<<"i"<<endl;
}


