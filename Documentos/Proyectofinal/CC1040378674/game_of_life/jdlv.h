#ifndef JDLV_H
#define JDLV_H

#include <iostream> 
#include <cstdlib>
#include <vector>
#include <unistd.h>

using namespace std;

class jdlv{
public:
    // int fil;
    // int col;
    
    jdlv(int);
    void setmapa();
    void setdim(int);    

    void dibujar();
    void analizarVecinos(int, int);
    void ciclo();

private:
    int dim;
    vector<vector<int> > mapa;

    int vecinos1;
    int vecinos2;
};

#endif
