//Ahora sigue la seccion de implementacion de la clase que es donde definimos las funciones o metodos de la clase

#include <iostream>
using namespace std; //espacio de nombres
#include <iomanip> //para los manipuladores
#include <cmath> //para funciones matematicas
#include "declaracion.h" //importamos la declaracion de la clase Rectangulo

Rectangulo::Rectangulo(double l, double a) //constructor
{
  largo=l;
  ancho=a;
}

void Rectangulo::asignarDatos(double l, double a)
{
  largo=l;
  ancho=a;
  return ;
}

double Rectangulo::asignarAncho(double a)
{
  ancho=a;
  return ancho;
}

double Rectangulo::asignarLargo(double l)
{
  largo=l;
  return largo ;
}

float Rectangulo::area() 
{
  float arearec;
  arearec=largo*ancho;
  return arearec;
}

float Rectangulo::perimetro() 
{
  float perimerec;
  perimerec=2*largo+2*ancho;
  return perimerec ;
}

void Rectangulo::mostrarDatos()
{
  float per;
  float are;
  are=area();
  per=perimetro();
    
  cout <<"el area de este rectangulo es: " << are << endl;
  cout <<"el perimetro de este rectangulo es: " << per << endl;
  return ;
}

void Rectangulo::obtenerAncho()
{
  cout <<"el ancho de este rectangulo es: " << asignarAncho(ancho) << endl;
  return ;
}

void Rectangulo::obtenerLargo()
{
  cout <<"el largo de este rectangulo es: " << asignarLargo(largo) << endl;
  return ;
}
