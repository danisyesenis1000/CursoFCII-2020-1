#include <iostream>
using namespace std; //espacio de nombres
#include <iomanip> //para los manipuladores
#include <cmath> //para funciones matematicas

#include "declaracion.h"


int main() //funcion principal
{

  complejo num1;
  num1.asignarDatos(55,74); //asignamos los datos
  num1.obtenerParteReal(); //asignamos la parte real
  cout << "parte real " << num1.obtenerParteReal() << endl; //imprimir parte real
  num1.obtenerParteImaginaria();//asignamos la parte imaginaria
  cout << "parte imaginaria " << num1.obtenerParteImaginaria() << endl; //imprimir parte imaginaria
  num1.mostrarnumero();//mostrar el complejo
  cout << "otro numero complejo" << endl;
  complejo num2;
  num2.asignarDatos(23,-5);
  num2.obtenerParteReal(); //asignamos la parte real
  cout << "parte real " << num2.obtenerParteReal() << endl; //imprimir parte real
  num2.obtenerParteImaginaria();//asignamos la parte imaginaria
  cout <<"parte imaginaria " << num2.obtenerParteImaginaria() << endl; //imprimir parte imaginaria
  num2.mostrarnumero();//mostrar el complejo
  cout << "veamos suma y resta de los anteriores numeros complejos" << endl;
  complejo num3; //num3 va ser la suma de num1 y num2 y la resta de num1 y num2
  num3.Suma(num1.obtenerParteReal(),num2.obtenerParteReal(),num1.obtenerParteImaginaria(),num2.obtenerParteImaginaria());
  num3.Resta(num1.obtenerParteReal(),num2.obtenerParteReal(),num1.obtenerParteImaginaria(),num2.obtenerParteImaginaria());
  
  return 0;
}

