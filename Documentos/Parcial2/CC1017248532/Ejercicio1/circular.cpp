#include "utils/circular.h"

Circular::Circular(double r, double w, double dt, int n, double phi){

  R = r;
  W = w;
  dT = dt;
  N = n;
  Phi = phi;
}

double Circular::xpos(double t){

  return R*cos( W*t + Phi );
}

double Circular::ypos(double t){

  return R*sin( W*t + Phi );
}

Circular::~Circular() {
    cout << "Circular destructed" << endl;
}

void Circular::PrintTimeEvolution(){
    
    ofstream file;
    
    file.open("datos_circular.csv");
    
    file << "x,y" << endl;
    
    for(int i = 0; i < N; i++){
        file << xpos(i*dT) << "," << ypos(i*dT) << endl;
        
    }
}

