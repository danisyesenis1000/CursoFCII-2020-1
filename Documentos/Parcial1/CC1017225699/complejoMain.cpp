
#include <iostream>
using namespace std;

#include "complejo.h" // NOTE: inclulle la definicion de la clase

int main()
{
    Complejo c1=Complejo(1.,1. );
    Complejo c2=Complejo(2.,3. );

    Complejo c3=c1.Sum(c2);
    Complejo c4=c1.Res(c2); 
    cout << "El primer numero imaginario es: ";
    c1.displayMessage();
    cout << "El segundo numero imaginario es: ";
    c2.displayMessage();
    cout << "su suma es: ";
    c3.displayMessage();
    cout << "su resta es: ";
    c4.displayMessage();


    cout << "Parte imaginaria del primero es: " <<  c1.getParteReal()<<endl; 
    cout << "Parte imaginaria del primero es: " << c1.getParteImag()<<endl;
    
    return 0; 
} 

