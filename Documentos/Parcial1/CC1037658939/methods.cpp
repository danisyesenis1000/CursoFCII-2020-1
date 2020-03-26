#include <iostream>

/*
 * methods.cpp
 * 
 * Methods for class Complejo.
 * Requires complexar.h.
 * 
 * Carolina Herrera S.
 * 
 * */

using namespace std;

#include "complexar.h"

Complejo::Complejo(){
    ParteReal = 0;
    ParteImaginaria = 0;
}

void Complejo::asignarDatos( double a, double b ){
    ParteReal = a;
    ParteImaginaria = b;
}

double Complejo::obtenerParteReal(){
    return ParteReal;
}

double Complejo::obtnerParteImaginaria(){
    return ParteImaginaria;
}

Complejo Complejo::suma( Complejo c ){
    Complejo suma;
    
    suma.asignarDatos( ParteReal+c.obtenerParteReal(), ParteImaginaria+c.obtnerParteImaginaria() );
    
    return suma;
}

Complejo Complejo::resta( Complejo c ){
    Complejo resta;
    
    resta.asignarDatos( ParteReal-c.obtenerParteReal(), ParteImaginaria-c.obtnerParteImaginaria() );
    
    return resta;
}

void Complejo::mostrarDato(){
    
    cout << ParteReal << " + " << ParteImaginaria << "i" << endl;
}

