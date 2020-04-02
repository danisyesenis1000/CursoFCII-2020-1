#include <iostream>
#include "complexar.h"

/*
 * punto_3.cpp
 * 
 * Usage of class Complejo
 * Requires complexar.h and methods.cpp
 * 
 * Carolina Herrera S.
 * 
 * */


int main(){
    Complejo c1, c2;
    Complejo c3;
    
    // Assign real and imaginary parts
    c1.asignarDatos(1.1, 2.5);
    c2.asignarDatos(3.7, 4.2);
    
    // Show numbers
    c1.mostrarDato();
    c2.mostrarDato();
    
    cout << endl;
    
    // Add numbers and print result
    cout << "suma: " << endl;
    c3 = c1.suma( c2 );
    c3.mostrarDato();
    
    cout << endl;
    
    // Subtract numbers and print result
    cout << "resta: " << endl;
    c3 = c1.resta( c2 );
    c3.mostrarDato();
    
    return 0;
}
