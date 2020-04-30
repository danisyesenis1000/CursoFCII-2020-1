#include "espiral.h"
//#include "circular.h"
#include <iostream>
using namespace std;


# include <cmath>

espiral::espiral( double z0, double v, double radio, double omega, double alfa, double tiempo):circular( radio, omega, alfa, tiempo )
{
    setZ0( z0);
    setV( v );
    
    setRadio( radio);
    setOmega( omega );
    setAlfa( alfa );
    setTiempo( tiempo );
    
    setXpos(radio, omega, alfa, tiempo);
    setYpos(radio, omega, alfa, tiempo);
    setZpos(z0,v,tiempo);        
} 


espiral::~espiral(){}

void espiral::setZ0( double z0 )
{
   EspZ0 = z0; 
} 

void espiral::setV( double v )
{
   EspV = v; 
}

void espiral::setZpos( double z0, double v, double tiempo)
{
   EspZpos = z0 + v*tiempo; 
}

double  espiral::getZ0()
{
   return EspZ0; 
} 

double  espiral::getV()
{
   return EspV; 
}

double  espiral::getZpos()
{
   return EspZpos; 
}
