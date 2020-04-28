#include "utils/espiral.h"

Espiral::Espiral(double R, double W, double dT, int N, double Phi, double z0, double vz) 
: Circular(R, W, dT, N, Phi), Z0(z0), Vz(vz) {}


double Espiral::zpos(double t){

  return Z0 + Vz*t;
}

void Espiral::PrintTimeEvolution(){
    
    ofstream file;
    
    file.open("datos_espiral.csv");
    
    file << "x,y,z" << endl;
    
    for(int i = 0; i < N; i++){
        file << Circular::xpos(i*dT) << "," << Circular::ypos(i*dT) << "," << zpos(i*dT) << endl;
        
    }
}

Espiral::~Espiral(){
    
    cout << "Espiral destructed" << endl;
}
