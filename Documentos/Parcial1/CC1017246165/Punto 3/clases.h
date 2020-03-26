#include<iostream>
#include<cmath>
#include<iomanip>


using namespace std;

//Numeros complejos con clase

class complejo{
private:
  double ParteReal1,ParteImaginaria1,ParteReal2,ParteImaginaria2;
public:
  complejo(double,double,double,double); //Constructor
  void AsignarDatos(double,double,double,double);
  double SumaComplejos1();
  double SumaComplejos2(); 
  double RestaComplejos1();
  double RestaComplejos2();
  double FormaCompleja();
  void ObtenerParteReal();
  void ObtenerParteImaginaria();
};
