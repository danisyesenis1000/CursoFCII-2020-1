#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

#define CUSTOMPRINT std::setw(12) << std::fixed << std::setiosflags(std::ios::left) << std::setprecision(2) <<
/*
Compilation: g++ ClassWork.cpp -o ClassWork.exe
*/

int main()
{
  //VARIABLES
  std::string Parameters[6] = {"Length", "Width", "Depth", "Perimeter", "Volume", "Surface area"};
  double length = 25.0, width = 10.0, depth = 5.0;
  double perimeter, volume, surface_area;

  //Header printing
  for (int i = 0; i < 6; i++)
  {
    std::cout << std::setw(12) << std::setiosflags(std::ios::left) << Parameters[i];
  }
  std::cout << std::endl; 

  for (int i = 0; i < 72; i++)
  {
    std::cout << "*";
  }
  std::cout << std::endl; 


  //Output printing
  for (length = 25.0; length <= 30.0; length += 5.0)
  {
      for (depth = 5.0; depth <= 6.5; depth += 0.5)
        {
          //COMPUTATION
          perimeter = 2.0 * (length + width);
          volume = length * width * depth;
          surface_area = perimeter * depth + length * width;

          //OUTPUT
          std::cout << 
          CUSTOMPRINT length <<
          CUSTOMPRINT width << 
          CUSTOMPRINT depth << 
          CUSTOMPRINT perimeter << 
          CUSTOMPRINT volume <<
          CUSTOMPRINT surface_area << std::endl;
        }
      width += 2.0; //recalculation of width
  }

  return(0);
}
