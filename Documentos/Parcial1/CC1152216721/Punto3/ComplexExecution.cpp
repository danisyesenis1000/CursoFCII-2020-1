#include"ComplexHeader.h"

int main()
{
  //Creation of objects: three complex numbers to test class methods
  Complex z1(2.0, 3.0);
  Complex z2(5.0, 7.0);
  Complex z3(11.0, 13.0);
  
  //Print the three numbers
  std::cout << "Printing complex numbers: " << std::endl;
  z1.PrintNumber();
  z2.PrintNumber();
  z3.PrintNumber();
  
  std::cout << "\nPerforming aritmetic operations: " << std::endl;
  //Add z3 to z1; output: complex variable Sum = z1 + z3
  Complex Sum = z1.Add(z3);
  Sum.PrintNumber();
  
  //Subtract z3 from z2; output: complex variable Dif = z2 - z3
  Complex Dif = z2.Subtract(z3);
  Dif.PrintNumber();
  
  return(0);
}
