//Ahora sigue la seccion de implementacion de la clase que es donde definimos las funciones o metodos de la clase

#include <iostream>
using namespace std; //espacio de nombres
#include <iomanip> //para los manipuladores
#include <cmath> //para funciones matematicas
#include "declaracion.h" //importamos la declaracion de la clase Rectangulo

Rectangulo::Rectangulo(int l, int a) //constructor
{
  largo=l;
  ancho=a;
}

void Rectangulo::asignarDatos(int l, int a)
{
  largo=l;
  ancho=a;
  return ;
}

void Rectangulo::asignarAncho(int a)
{
  ancho=a;
  return ;
}

void Rectangulo::asignarLargo(int l)
{
  largo=l;
  return ;
}

void Rectangulo::area() 
{
  float arearec;
  arearec=largo*ancho;
  return ;
}

void Rectangulo::perimetro() 
{
  float perimerec;
  perimerec=2*largo+2*ancho;
  return ;
}

void Rectangulo::mostrarDatos()
{
  
  cout <<"el area de este rectangulo es: " << float(largo*ancho) << endl;
  cout <<"el perimetro de este rectangulo es: " << float(2*largo+2*ancho) << endl;
  return ;
}

void Rectangulo::obtenerAncho()
{
  cout <<"el ancho de este rectangulo es: " << ancho << endl;
  return ;
}

void Rectangulo::obtenerLargo()
{
  cout <<"el largo de este rectangulo es: " << largo << endl;
  return ;
}
