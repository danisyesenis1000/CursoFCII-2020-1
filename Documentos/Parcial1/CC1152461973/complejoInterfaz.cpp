#include <iostream>
using namespace std;
#include "complejo.h"

complejo::complejo(double real1Inp, double im1Inp, double real2Inp, double im2Inp)
{
  cout<< "Ingrese la parte real del primer número complejo: "<<endl;
  cin>> real1Inp;
  cout<< "Ingrese la parte imaginaria del primer número complejo: "<<endl;
  cin>> im1Inp;
  cout<< "Ingrese la parte real del segundo número complejo: "<<endl;
  cin>> real2Inp;
  cout<< "Ingrese la parte imaginaria del segundo número complejo: "<<endl;
  cin>> im2Inp;

  ParteReal1 = real1Inp;
  ParteImaginaria1 = im1Inp;
  ParteReal2 = real2Inp;
  ParteImaginaria2 = im2Inp;
}

void complejo::AsignarDatos(double r1,double i1,double r2,double i2)
{
  ParteReal1 = r1;
  ParteReal2 = r2;
  ParteImaginaria1 = i1;
  ParteImaginaria2 = i2;
}

double complejo::SumaReal()
{
  return ParteReal1 + ParteReal2;
}

double complejo::RestaReal()
{
  return ParteReal1 - ParteReal2;
}

double complejo::SumaImaginaria()
{
  return ParteImaginaria1 + ParteImaginaria2;
}

double complejo::RestaImaginaria()
{
  return ParteImaginaria1 - ParteImaginaria2;
}


void complejo::ObtenerParteReal()
{
  cout<<"La parte real del primer número es: "<<ParteReal1<<endl;
  cout<<"La parte real del segundo número es: "<<ParteReal2<<endl;
  cout<<"La parte real de la suma es: "<<SumaReal()<<endl;
  cout<<"La parte real de la resta es: "<<RestaReal()<<endl;
}

void complejo::ObtenerParteImaginaria()
{
  cout<<"La parte imaginaria del primer número es: "<<ParteImaginaria1<<endl;
  cout<<"La parte imaginaria del segundo número es: "<<ParteImaginaria2<<endl;
  cout<<"la parte imaginaria de la suma es: "<<SumaImaginaria()<<endl;
  cout<<"la parte imaginaria de la resta es: "<<RestaImaginaria()<<endl;
}

void complejo::ImpresionDatos()
{
  cout<<"El primer número es:  "<<ParteReal1<< " + "<< ParteImaginaria1<<"i"<<endl;
  cout<<"El segundo número es:  "<<ParteReal2<< " + "<<ParteImaginaria2<<"i"<<endl;
  cout<<"La suma de los numeros es:  "<<SumaReal()<< " + "<<SumaImaginaria()<<"i"<<endl;
  cout<<"La resta de los numeros es:  "<<RestaReal()<< " + "<<RestaImaginaria()<<"i"<<endl;
}
