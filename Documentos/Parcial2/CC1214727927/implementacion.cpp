#include <iostream> //para utilizar cout 
#include <iomanip>
#include <string>//para utlizar cadenas de caracteres
#include <fstream> // flujo de archivo
#include <cstdlib>
#include <ctime>//libreria para random
#include <algorithm> //para poder utilizar algoritmos como el sor
#include <vector> //libreria para vectores
#include <cmath> //para funciones matematicas
#include "declaracion.h"
using namespace std;

Circular::Circular(float r, float fre, float delt, float total, int interdt, float alfa) //constructor
{
  R=r;
  w=fre;
  dt=delt;
  Total=total;
  Numsdt=interdt;
  fase=alfa;
}

void Circular::xpos(float arreglox[], int Numsdt) //posicion en x
{
  for(int T=0; T<Numsdt;T++)
    {
      arreglox[T]=R*cos(w*T*dt+fase);
    }
}

void Circular::ypos(float arregloy[], int Numsdt) //posicion en y
{
  for(int T=0; T<Numsdt;T++)
    {
      arregloy[T]=R*sin(w*T*dt+fase);
    }
  
}

Circular::~Circular() //destructor
{
}

Espiral::Espiral(float r, float fre, float delt, float total, int interdt, float alfa,float zini,float velz) //constructor de clase espiral
{
  R=r;
  w=fre;
  dt=delt;
  Total=total;
  Numsdt=interdt;
  fase=alfa;
  zo=zini;
  vz=velz;
}

void Espiral::zpos(float arregloz[], int Numsdt) //posicion en z
{
  for(int T=0; T<Numsdt;T++)
    {
      arregloz[T]=zo+vz*T*dt;
    }
  
}

Espiral::~Espiral() //destructor de clase espiral
{
}
