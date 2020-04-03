#include <iostream>
#include <iomanip>

using namespace std;

class Complejo{

 public:
  Complejo(double, double); //It will have real part and imaginary part as entries

  void AsignarDatos(double, double);
  
  double ObtenerParteReal(); //It will retrieve the real part
  double ObtenerParteImaginaria(); //it will retrieve the imaginary part

  double SumaComplejos(); //Will add the current complex number to another one
  double RestaComplejos(); //Will subtract the current complex number to another one

  void ImprimirComplejo(); //Prints the complex in a + bi format

 private:
  double ParteReal;
  double ParteImaginaria;
};
