#include <iostream>

using std::cout;
using std::endl;


class Rectangulo
{
 public:
  Rectangulo(); //Constructor
  //void asignarDatos();
  void asignarAncho(double);
  void asignarLargo(double);
  void area();
  void perimetro();
  void mostrarDatos();
  void obtenerAncho();
  void obtenerLargo();
  
 private:
  double largo;
  double ancho;

  double ar;
  double per;
};
