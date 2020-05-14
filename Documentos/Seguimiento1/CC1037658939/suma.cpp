#include <iostream>
#include <fstream>

/*
 * POO def: Se abordan los problemas por medio de una abstraccion que
 * permite definir objetos (por ejemplo clases) que tienen ciertas
 * características.
 * 
 * Clase def: Forma en la que se puede definir objetos con ciertas 
 * características comunes.
 * 
 * Uso: Simulaciones, por ejemplo. Hay muchos problemas que pueden 
 * plantearse en términos de la POO.
 * 
 * */



// Sums all integers from n1 to n2
int suma(int n1, int n2){
  int sum=0;

  while(n1<=n2){
    sum += n1;
    n1 += 1;
  }
  
  return sum;
}


int main(void){
  int a, b;
  int key;
  int result;
  
  std::cout << "Enter two integer numbers in order: " << std::endl;
  std::cin >> a >> b;

  result = suma(a, b);
  
  std::cout << "Type 1 for printing and any other number for file" << std::endl;
  std::cin >> key;

  if(key == 1){
    std::cout << "The sum is " << result << std::endl;
  }

  else {
    std::ofstream file;
     file.open("result.txt");
     file << result;
     file.close();
     std::cout << "Output in result.txt" << std::endl;
  }

  return 0;
}
