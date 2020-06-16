#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

#include "CircularEspiral.h"

int main()
{
    double r, w, dtiempo, A, Z, VZ;
    int N_int;
    cout<< "Ingrese el radio del movimiento circular: "<<endl;
    cin>> r;
    cout<< "Ingrese la frecuencia angular del movimiento circular: "<<endl;
    cin>> w;
    cout<< "Ingrese cada cuánto quiere que se mida la ubicación del cuerpo: "<<endl;
    cin>> dtiempo;
    cout<< "Ingrese el número de veces que desea hacerlo (un número entero por favor): "<<endl;
    cin>> N_int;
    cout<< "Ingrese la fase del movimiento circular: "<<endl;
    cin>> A;
    cout<< "Ingrese la posición inicial en z: "<<endl;
    cin>> Z;
    cout<< "Ingrese la velocidad inicial en z: "<<endl;
    cin>> VZ;
    
    Espiral helice(r, w, dtiempo, N_int, A, Z, VZ);
    helice.datosz();
    helice.zpos();
    return 0;
}
