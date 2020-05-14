#include <iostream>
#include <string>

using namespace std;

/*
 * rectangulo.h
 * 
 * This class represents a rectangle.
 * 
 * Carolina Herrera S.
 * 
 * */

//class definition
class Rectangulo
{
public:
  Rectangulo();
  void asignarDatos( double, double );
  void asignarAncho( double );
  void asignarLargo( double );
  double area();
  double perimetro();
  void mostrarDatos();
  double obtenerAncho();
  double obtenerLargo();

private:
  double largo;
  double ancho;
};
