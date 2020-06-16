#include"ComplexHeader.h"

//FUNCTIONS AND METHODS

//Constructor
Complex::Complex(double NumRealPart, double NumImagPart)
{
  SetData(NumRealPart, NumImagPart);
}

//Sets real and imaginary parts on the complex number
void Complex::SetData(double NumRealPart, double NumImagPart)
{
  RealPart = NumRealPart;
  ImagPart = NumImagPart;
}

//When called as VARIABLE.GetRealPart(), returns the double precision
//real part of VARIABLE, which is of type "Complex"
double Complex::GetRealPart()
{
  return(RealPart);
}

//When called as VARIABLE.GetImagPart(), returns the double precision
//imaginary part of VARIABLE, which is of type "Complex" defined above
double Complex::GetImagPart()
{
  return(ImagPart);
}

//When called as VARIABLE.Add(CNUM), gives the complex sum of
//VARIABLE and CNUM, both of which are of type "Complex" defined above
Complex Complex::Add(Complex NumZ)
{
  double RealZ = NumZ.GetRealPart();
  double ImagZ = NumZ.GetImagPart();
  
  Complex Sum(RealPart + RealZ, ImagPart + ImagZ);
  
  return(Sum);
}

//When called as VARIABLE.Subtract(CNUM), gives the result of complex
//subtract CNUM from VARIABLE, both of which are of type "Complex"
Complex Complex::Subtract(Complex NumZ)
{
  double RealZ = NumZ.GetRealPart();
  double ImagZ = NumZ.GetImagPart();
  
  Complex Difference(RealPart - RealZ, ImagPart - ImagZ);
  
  return(Difference);
}

//Prints the complex number as RealPart + ImagPart i, where the sign on
//the middle is printed depending on the sign of the imaginary part
void Complex::PrintNumber()
{
  std::string sign = " + ";
  
  if(ImagPart < 0)
  {
    sign = " - ";
  }
  
  std::cout << std::setw(12) << std::fixed << std::setprecision(3) << std::scientific << RealPart 
            << std::setw(5) << sign 
            << std::setw(12) << std::fixed << std::setprecision(3) << std::scientific << std::abs(ImagPart) 
            << " i " << std::endl;
}
