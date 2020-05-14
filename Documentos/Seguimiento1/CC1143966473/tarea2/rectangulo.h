/*
TAREA 2

Diseñar una clase llamada Rectangulo que tenga como datos miembro en doble precision largo y ancho y las funciones miembre de asignarDatos, asignarAncho, asignarLargo, area,perimetro, mostrarDAtos, obtenerAncho y obtenerLargo

 */

#include<string>
#include<cmath>
using std::string;



//Declaracion de la clase

class Rectangulo
{
public:
  Rectangulo(double =0,double =0); // constructor de la clase
  void asignarDatos(double,double); // prototipos de la diferentes funciones
  double asignarAncho();
  double asignarLargo();
  double area();
  double perimetro();
  void mostrarDatos();
  void obtenerAncho();
  void obtenerLargo();
  
private:
  double largo; //miembros de datos
  double ancho;
  
};
