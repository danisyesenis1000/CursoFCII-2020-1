#include<iostream>
#include<cmath>
#include<iomanip>


class complejo{
private:
  double ParteReal1, ParteImaginaria1, ParteReal2, ParteImaginaria2;
public:
  complejo(double,double,double,double); //Constructor
  void AsignarDatos(double,double,double,double);
  double SumaComplejos();
  double RestaComplejos();
  double FormaCompleja();
  void ObtenerParteReal();
  void ObtenerParteImaginaria();
};
