/*
Diseñe una clase llamada Rectangulo que tenga como datos miembro en doble precisión largo y ancho. Y las funciones
miembro de asignarDatos, asignarAncho, asignarLargo, area, perimetro, mostrarDatos, obtenerAncho y obtenerLargo
 */

#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

class Rectangulo{
 public:
  Rectangulo(double, double);
  void AsignarDatos(double, double);
  void AsignarAncho(double);
  void AsignarLargo(double);
  double CalcularArea();
  double CalcularPerimetro();
  void MostrarDatos();
  double ObtenerAncho();
  double ObtenerLargo();

 private:
  double Largo;
  double Ancho;
  double Perimetro;
  double Area;
};
