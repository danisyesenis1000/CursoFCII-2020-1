#include "circular.h"
# include <cmath>
#include <iostream>
using namespace std;

circular::circular( double radio, double omega, double alfa, double tiempo )
{
    setRadio( radio);
    setOmega( omega );
    setAlfa( alfa );
    setTiempo( tiempo );
    setXpos(radio, omega, alfa, tiempo);
    setYpos(radio, omega, alfa, tiempo);    
}

circular::~circular(){}


void circular::setRadio( double radio )
{
   CirRadio = radio; 
} 

void circular::setOmega( double omega )
{
   CirOmega = omega; 
}

void circular::setAlfa( double alfa)
{
   CirAlfa = alfa; 
}

void circular::setTiempo( double tiempo)
{
   CirTiempo = tiempo; 
}
void circular::setXpos( double radio, double omega, double alfa, double tiempo )
{
   CirXpos = radio*cos(omega*tiempo + alfa); 
}

void circular::setYpos( double radio, double omega, double alfa, double tiempo )
{
   CirYpos = radio*sin(omega*tiempo + alfa); 
}

double  circular::getRadio()
{
   return CirRadio; 
} 

double  circular::getOmega()
{
   return CirOmega; 
}

double  circular::getAlfa()
{
   return CirAlfa; 
}

double  circular::getTiempo()
{
   return CirTiempo; 
}

double  circular::getXpos()
{
   return CirXpos; 
}

double  circular::getYpos()
{
   return CirYpos; 
}



