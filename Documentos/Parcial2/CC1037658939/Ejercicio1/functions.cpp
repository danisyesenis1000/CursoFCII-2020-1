#include <iostream>
#include <cmath>
#include <fstream>
#include "circular.h"

using namespace std;

/*
 * functions.cpp
 * 
 * Functions for class Circular.
 * 
 * Carolina Herrera S.
 * Last update: april 27, 2020
 * 
 * */

// Constructor
Circular::Circular( double R, double w, double del_t, double T,
                    double N, double alpha){
    
    radius = R;
    ang_freq = w;
    dt = del_t;
    total_time = T;
    num_time_inter = N;
    phase = alpha;
}

// x position in a given time
double Circular::xpos( double t ){
    
    return radius*cos(ang_freq*t + phase);
}

// y position in a given time
double Circular::ypos( double t ){
    
    return radius*sin(ang_freq*t + phase);
}

// Save evolution in a file
void Circular::save_evolution(){
    ofstream file( "data_circular.csv", ios::out );
    double x, y;
    double t = 0;
    
    file << "x_pos; y_pos" << endl;
    
    while ( t <= total_time ){
        x = xpos(t);
        y = ypos(t);
        
        t += dt;
        
        file << x << ";" << y << endl;
    }
    
    file.close();
}

// Plot result of evolution in python
void Circular::plot(){
    
    system("python plot.py C");
}

// Destructor
Circular::~Circular(){
    cout << "Erasing object." << endl;
}
