/*
Program to add the positive integer numbers between n1 and n2 
from user input, chosing wether they are to be printed on 
screen or saved on a file.

Compilation: g++  Sum_n1n2.cpp -lm -o Sum_n1n2.exe
Execution: ./Sum_n1n2.exe n1 n2 opt

Execution-time arguments:
n1: first integer, left bound
n2: second integer, right bound
opt: output option:
  opt = 0: print on screen
  opt = 1: print to file Sum_n1n2.dat
*/

/*
Programación orientada a objetos: Paradigma de programación que permite
que la escritura y ejecución de programas sea más modular, donde los 
objetos son estructuras que pueden estar compuestas de varias propiedades
que en la ejecución del programa son manipuladas sin crear una cantidad
excesiva de variables.

Clases: Análogo a lo que en C normal es una estructura; tipo de "variable"
que puede ser definida por el usuario, conteniendo propiedades y variables
internas que luego se pueden manipular.

Uso en C++: Programas modulares, más legibles, y posibilidad de crear
estructuras más complejas.
*/

#include <iostream>
#include <fstream>

//Function to compute the sum of integers from n1 to n2
int sum_n1n2(unsigned int n1, unsigned int n2)
{
  //For loop counter
  unsigned int i = 0;

  //Output variable
  unsigned int output = 0;

  //For loop
  for ( i = n1; i <= n2; i++)
  {
    output += i;
  }

  return(output);
}

int main(int argc, char **argv)
{
  //Values for n1, n2 and opt from execution input
  unsigned int n1 = (unsigned int) std::stoul(argv[1], nullptr, 0);
  unsigned int n2 = (unsigned int) std::stoul(argv[2], nullptr, 0);
  unsigned int opt = (unsigned int) std::stoul(argv[3], nullptr, 0);

  //Runtime variables
  unsigned int out_sum = 0;
  std::ofstream outfile;

  //Execution
  out_sum = sum_n1n2(n1, n2);

  //Output option
  if (opt == 0)
  {
    std::cout << "Sum of integers from " << n1 << " to " << n2 << " is " << out_sum << std::endl;
  }
  else if (opt == 1)
  {
    outfile.open("Sum_n1n2.dat");
    outfile << "Sum of integers from " << n1 << " to " << n2 << " is " << out_sum << std::endl;
    outfile.close();
  }

  return(0);
}
