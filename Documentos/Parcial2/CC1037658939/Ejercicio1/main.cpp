#include <iostream>
#include <fstream>
#include "circular.h"
#include "espiral.h"

/*
 * main.cpp
 * 
 * Usage of classes Circular and Espiral.
 * Requires functions.cpp, circular.h,
 * functions_esp.cpp and espiral.h
 * 
 * Carolina Herrera S.
 * Last update: april 27, 2020
 * 
 * */

int main(){
    Circular circ1(1, 0.5, 0.01, 10, 100, 0.1);
    Espiral esp1(1, 0.5, 0.01, 500, 100, 0.1, 3, 1);
    
    // Saves evolution to file
    circ1.save_evolution();
    esp1.save_evolution();
    
    // Plots result
    circ1.plot();
    esp1.plot();
    
    return 0;
}
