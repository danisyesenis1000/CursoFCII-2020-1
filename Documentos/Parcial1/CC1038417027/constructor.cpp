#include <iostream>
#include "variables.h"

using namespace std;


imag::imag(double r, double i)
{
  asignarDatos(r,i);
}
void imag::asignarDatos(double a,double i)
{
  parteReal = a;
  parteImaginaria = i;
}
//Retorno de parte real e imaginaria 
double imag::obtenerParteReal(){ return parteReal;}
double imag::obtenerParteImaginaria(){ return parteImaginaria;}
//-----------------------------------------------------------
//Para la suma y la resta se ingresan la parte real e imaginaria del numero complejo a suma o restar respectivamente 
void imag::sumaNumerosComplejos(double R1,double I1)
{
  double R = obtenerParteReal() + R1;
  double I = obtenerParteImaginaria() + I1;
  cout<<"Se suman los numeros complejos"<<endl;
  cout<<obtenerParteReal()<<" + i"<<obtenerParteImaginaria()<<" y "<<R1<<" + i"<<I1<<endl; 
  cout<<"y el resultado de la suma es: "<<R<<" + i"<<I<<"\n"<<endl; 
}

void imag::restaNumerosComplejos(double R1,double I1)
{
  double R = obtenerParteReal() - R1;
  double I = obtenerParteImaginaria() -I1;
  cout<<"Se restan los numeros complejos"<<endl;
  cout<<obtenerParteReal()<<" + i"<<obtenerParteImaginaria()<<" y "<<R1<<" + i"<<I1<<endl;
  if (I<0)
    {
      cout<<"El resultado de la resta es: "<<R<<" - i"<<-1*I<<endl;
    }
  else
    cout<<"El resultado de la resta es: "<<R<<" + i"<<I<<endl; 
}

void imag::mostrarNumeroComplejo()
{
  cout<<"El numero complejos ingresado es: \n"<<obtenerParteReal()<<" + i"<<obtenerParteImaginaria()<<endl;
  cout<<"\n"<<endl;
}

