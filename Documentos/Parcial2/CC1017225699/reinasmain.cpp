#include "reinas.h"
#include <iostream>
 
using namespace std;

int main() 
{
    cout << "Este programa soluciona el problema de las 8 reinas."
    << "\n \nA continuación se imprime la solucion."
    << "\n \n0-> casillas vacias, 1-> reinas posicionadas "
    << "\n" <<endl;
    reinas R(8);
    R.solR(); 
    return 0; 
} 
