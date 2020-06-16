#include "utils/circular.h"
#include "utils/espiral.h"

#include <fstream>
#include <string>


int main(){
    double r = 1.0;
    double w = 1.0;
    double dt = 0.01;
    int n = 10000;
    double a = 0.0;
    double t = n*dt;
    
    double zo = 0;
    double vz = 1;
    
    Espiral E(r,w,dt,t,n,a, zo, vz);
    Circular C(r,w,dt,t,n,a);
    
    C.PrintTimeEvolution();
    E.PrintTimeEvolution();
    
    return 0;
}
