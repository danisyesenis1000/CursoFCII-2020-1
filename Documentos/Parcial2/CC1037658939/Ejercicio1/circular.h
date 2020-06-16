#include <iostream>

using namespace std;

/*
 * circular.h
 * 
 * Prototype for class Circular.
 * 
 * Carolina Herrera S.
 * Last update: april 27, 2020
 * 
 * */

class Circular {
    public:
    Circular( double, double, double, double, double, double );
    double xpos( double );
    double ypos( double );
    void save_evolution ();
    void plot();
    ~Circular();
    
    protected:
    double radius;
    double ang_freq;
    double dt;
    double total_time;
    double num_time_inter;
    double phase;
};

