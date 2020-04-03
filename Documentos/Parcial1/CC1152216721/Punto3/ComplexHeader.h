#include<iostream>
#include<iomanip>
#include<string>

//CLASS DEFINITION
class Complex
{
  public:
    Complex(double, double);
    void SetData(double, double);
    double GetRealPart();
    double GetImagPart();
    Complex Add(Complex);
    Complex Subtract(Complex);
    void PrintNumber();
    
  private:
    double RealPart;
    double ImagPart;
};
