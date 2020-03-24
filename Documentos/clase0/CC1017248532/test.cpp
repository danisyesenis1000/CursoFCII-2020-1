/*
Programacion orientada a objetos: consiste en orientar el codigo a escrito de forma que tenga una aplicalibidad general,
es decir, que sea reutilizable. De esta forma se puede programar algo que sera utilizado en el codigo a ser escrito de forma repetitiva y, se evita asi, tener que escribir lo mismo una y otra vez

Clase: es aquello que se programa cuando se hace uso de la programacion orientada a objetos. Las clases tienen propiedades y metodos, donde
los metodos son funciones que alteran propieades de la clase o generan outputs de algo necesario.

Uso: los usos son muchos, un ejemplo claro es el diseño de GUI's donde cada item de la GUI es una clase, por ejemplo, un boton que cumple 
ciertas funciones
*/

#include <iostream>
#include <fstream>
using namespace std;

int sum_n1n2(int a, int b){

  int result;
  for(int i = a; i <= b; i++){
    result += i;
      }
  return result;
}

int main(){
  int n1, n2, sum, Q;
  
  cout << "Input the first number: ";
  cin >> n1;
  cout << "Input the second number: ";
  cin >> n2;

  sum = sum_n1n2(n1,n2);

  cout << "Press 0 if you want the result printed in screen or press 1 if you want it as a file: ";
  cin >> Q;
  
  if(Q == 0){
    cout << sum << "\n";
  }
  
  else if (Q == 1){
    cout << "Your result was saved as result.txt" << "\n";
    ofstream outfile;
    outfile.open("result.txt");
    outfile << sum;
    outfile.close();
    }
  return 0;
}
