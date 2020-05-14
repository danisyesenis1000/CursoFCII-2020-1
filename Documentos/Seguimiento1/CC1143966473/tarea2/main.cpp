#include<iostream>
#include<string>
#include<cmath>
#include "rectangulo.h"
using namespace std;

int main()
{
  double largo=20.1923;
  double ancho=3.12231;
  Rectangulo rectangulo(largo,ancho);

  //Si solamente queremos tener el ancho llamamos la funcion obtenerAncho
  cout<<"\n====Ancho===="<<endl;
  rectangulo.obtenerAncho();
  
  //Si solamente queremos tener el Largo llamamos la funcion obtenerLargo
  cout<<"\n====Largo===="<<endl;
  rectangulo.obtenerLargo();
  
  //Si queremos tener todos los datos llamamos la funcion mostrarDatos

  cout<<"\n====Datos===="<<endl;
  rectangulo.mostrarDatos();
  return 0;
}
