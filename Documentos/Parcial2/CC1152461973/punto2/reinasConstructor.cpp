#include <iostream>
#include <iomanip>
#include<stdlib.h>
#include<time.h>
#include <vector>

#include "reinas.h"

using namespace std;

IdentificadorReinas::IdentificadorReinas(int f1, int f2, int col1, int col2)
{
    columna1 = col1;
    fila1 = f1;
    columna2 = col2;
    fila2 = f2;
    
}

IdentificadorReinas::~IdentificadorReinas()
{
}

bool IdentificadorReinas::Amenaza()
{
    bool riesgo = fila1==fila2 || columna1==columna2 ||(fila1+columna1) == (fila2+columna2) || (fila1-columna1) == (fila2-columna2);
    
    return riesgo;    
}
