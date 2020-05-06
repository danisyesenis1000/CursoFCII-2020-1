#include "utils/espiral.h"

Espiral::Espiral(double R, double W, double dT, double T, int N, double Phi, double z0, double vz) 
: Circular(R, W, dT, T, N, Phi), Z0(z0), Vz(vz) {}


double Espiral::zpos(double t){

  return Z0 + Vz*t;
}

void Espiral::PrintTimeEvolution(){
    
    ofstream file;
    
    file.open("datos_espiral.csv");
    
    file << "t,x,y,z" << endl;
    
    for(int i = 0; i < N; i++){
      file << i*dT << "," << Circular::xpos(i*dT) << "," << Circular::ypos(i*dT) << "," << zpos(i*dT) << endl;
        
    }
  file.close();
}

Espiral::~Espiral(){
    
    cout << "Espiral destructed" << endl;
}
