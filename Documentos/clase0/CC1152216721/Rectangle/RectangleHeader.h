//Definición de la clase "Rectangulo", con sus datos y funciones miembro

#include <iostream>
#include <vector>

class Rectangulo
{
public:
  Rectangulo(); 
  void obtenerLargo();
  void obtenerAncho();
  double asignarLargo( double Largo );
  double asignarAncho( double Ancho );
  double area();
  double perimetro();
  std::vector<double> asignarDatos( double Area, double Perimetro );
  void mostrarDatos( std::vector<double> Datos );

private:
  double largo;
  double ancho;
};
