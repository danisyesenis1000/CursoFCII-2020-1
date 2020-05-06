#include <iostream>
#include <iomanip>
#include<stdlib.h>
#include<time.h>
#include <vector>

using namespace std;

class IdentificadorReinas
{
    int columna1;
    int fila1;
    int columna2;
    int fila2;
public:
    IdentificadorReinas(int, int, int, int);
    ~IdentificadorReinas();

    bool Amenaza(); //cada que se agregue una reina se ve si esta amenazada por otras
};
