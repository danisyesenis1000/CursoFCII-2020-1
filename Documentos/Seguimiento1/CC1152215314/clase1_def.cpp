#include "clase1.h"

Rectangulo::Rectangulo(){largo=ancho=ar=per=0.0;}  //llamo al constructor e inicializo las variables

void Rectangulo::asignarAncho(double A)
{
  ancho=(A>0)?A:0.0;  //Condicion de que si es negativo entonces se pone 0.0
}

void Rectangulo::asignarLargo(double L)
{
  largo=(L>0)?L:0.0;  //Condicion de que si es negativo entonces se pone 0.0
}

void Rectangulo::area()
{
  ar=ancho*largo;  
}

void Rectangulo::perimetro()
{
  per=(2*ancho)+(2*largo);
}

void Rectangulo::obtenerAncho()
{
  cout << "El ancho que se ingreso fue: " << ancho << " u" << endl;
}

void Rectangulo::obtenerLargo()
{
  cout << "El largo que se ingreso fue: " << largo << " u" << endl;
}

void Rectangulo::mostrarDatos()
{
  cout << "El perimetro del rectangulo es: " << per << " u" << endl;
  cout << "El area del rectangulo es: " << ar << " u*u" << endl;
}
