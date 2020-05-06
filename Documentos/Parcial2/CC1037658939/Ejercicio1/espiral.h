#include <iostream>

using namespace std;

/*
 * espiral.h
 * 
 * Prototype for class Espiral.
 * 
 * Carolina Herrera S.
 * Last update: april 27, 2020
 * 
 * */

class Espiral: public Circular {
    public:
    Espiral( double, double, double, double,
             double, double, double, double );
    double zpos( double );
    void save_evolution();
    void plot();
    
    protected:
    double z_init;
    double vel_z;
    
};
