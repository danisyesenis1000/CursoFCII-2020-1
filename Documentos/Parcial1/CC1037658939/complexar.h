#include <iostream>

/*
 * complexar.h
 * 
 * This class represents a complex number and
 * allows complex aritmetic.
 * 
 * Carolina Herrera S.
 * 
 * */

using namespace std;

class Complejo{
public:
    Complejo();
    void asignarDatos( double, double );
    double obtenerParteReal();
    double obtnerParteImaginaria();
    Complejo suma( Complejo );
    Complejo resta( Complejo );
    void mostrarDato();

private:
    double ParteReal;
    double ParteImaginaria;
};
