#include <iostream>
#include <stdlib.h>
using namespace std;

class complejo
{	
 private:	
  double ParteReal1, ParteImaginaria1, ParteReal2, ParteImaginaria2;
  
 public:
  complejo(double,double,double,double);
  void AsignarDatos(double, double, double, double);	
  double SumaReal();
  double RestaReal();
  double SumaImaginaria();
  double RestaImaginaria();
  void ObtenerParteReal();
  void ObtenerParteImaginaria();
  void ImpresionDatos();
};
