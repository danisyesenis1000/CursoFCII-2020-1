//mi primer programa en C++
#include<iostream>

#define newline "n";//definimos un nuevo operador

using namespace std; //permite omitir el uso de "::std"

int main()
{
  cout<<"Bienvenidos a c++! \n";
 

  //TIPOS DE VARIABLES

  int j; //definicion - valor inicial indefinido
  int k = 0; //definicion con valor inicial
  int I(0); // definicion con inicializacion de constructor

  int m = k + I; // el inicializador puede ser cualquier expresion C++ valida

  int a,b = 0, c(b+5); // declaracion multiple

  std::cout<<m<<std::endl;

  std::cout<<"hola n ....."<<std::endl;

  //ARITMETICA
  //orden de precedencia, de izquierda a derecha

  return 0;
}
