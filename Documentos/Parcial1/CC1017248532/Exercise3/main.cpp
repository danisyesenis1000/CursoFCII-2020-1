#include "exercise3.h"

int main(){

  Complejo Complex(5.4,3.5);

  int Respuesta;

  cout << "¿Qué desea hacer? 0: sumar, 1: restar, 2: Imprimir el complejo \n";

  cin >> Respuesta;
  
  switch(Respuesta){

  case 0:
    Complex.SumaComplejos();
    break;

  case 1:
    Complex.RestaComplejos();
    break;

  case 2:
    Complex.ImprimirComplejo();
    break;

  default:
    cout << "Programa terminado. \n";
    break;
    
  }
  
  return 0;
}
