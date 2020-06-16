
#include <iostream>
using namespace std;

#include "complejo.h"

Complejo::Complejo( double preal, double pimag )
{
    asigDato(preal,pimag);
    
}

void Complejo::asigDato(double preal, double pimag){
    ParteReal = preal; 
    ParteImag = pimag;
} 

double  Complejo::getParteReal()
{
   return ParteReal; 
} 

double  Complejo::getParteImag()
{
   return ParteImag; 
}

Complejo  Complejo::Sum(Complejo C2)
{
   return Complejo(ParteReal+C2.ParteReal,ParteImag+C2.ParteImag); 
}
Complejo  Complejo::Res(Complejo C2)
{
   return Complejo(ParteReal-C2.ParteReal,ParteImag-C2.ParteImag); 
}

void Complejo::displayMessage()
{
   cout<< getParteReal() <<" + i"<< getParteImag() << endl;
}
