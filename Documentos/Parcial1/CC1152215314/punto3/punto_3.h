#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::fixed;
using std::setprecision;

/*
Para este codigo, un numero complejo sera un arreglo de dos entradas, donde la primera entrada sera la parte real y la segunda entrada la parte imaginaria, es decir, ver un numero complejo como un par ordenado --> Numero_Complejo = Numero[0] + i Numero[1]
 */

class Complejo{
 public:
  Complejo();                          //Constructor de la clase
  void MostrarNumeros();               //Muestro los numeros asignados
  void AsignarDatos1(double, double);  //Asigno numero1
  void AsignarDatos2(double, double);  //Asigno numero2
  void MostrarParteReal();             //muestra la parte real de los numeros que ingreso
  void MostrarParteImg();              //muestra la parte imaginaria de los numeros que ingreso
  void SumaNumeros();                  //funcion suma de complejos
  void RestaNumeros();                 //funcion resta de complejos
  void MultiplicaNumeros();            //funcion multiplica complejos
 private:
  double numero1[2];
  double numero2[2];
  double suma[2];
  double resta[2];
  double multiplicacion[2];
};
