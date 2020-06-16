#include <iostream>
#include <fstream>
#include "circular.h"
#include "espiral.h"

using namespace std;

/*
 * functions_esp.cpp
 * 
 * Functions for class Espiral.
 * 
 * Carolina Herrera S.
 * Last update: april 27, 2020
 * 
 * */

// Contructor
Espiral::Espiral( double R, double w, double del_t, double T,
                    double N, double alpha,
                    double z0, double vz) : Circular(R, w, del_t, T, N, alpha), z_init(z0), vel_z(vz){
    
    radius = R;
    ang_freq = w;
    dt = del_t;
    total_time = T;
    num_time_inter = N;
    phase = alpha;
    z_init = z0;
    vel_z = vz;
}

// z position in a given time
double Espiral::zpos( double t ){
    
    return z_init + vel_z*t;
}

// Save evolution in a file
void Espiral::save_evolution(){
    ofstream file( "data_espiral.csv", ios::out );
    double x, y, z;
    double t = 0;
    
    file << "x_pos; y_pos; z_pos" << endl;
    
    while ( t <= total_time ){
        x = xpos(t);
        y = ypos(t);
        z = zpos(t);
        
        t += dt;
        
        file << x << ";" << y << ";" << z << endl;
    }
    
    file.close();
}

// Plot result of evolution in python
void Espiral::plot(){
    
    system("python plot.py E");
}

