#include <iostream>
#include <iomanip>
#include<stdlib.h>
#include<time.h>
#include <vector>

#include "reinas.h"

using namespace std;

int main()
{
 int dimension = 8; //numero de reinas, filas y columnas
 srand(time(NULL));
 int tablero[dimension+1][dimension+1]= {0};
 int reina[dimension+1];
 reina[0]= 0;
 reina[1]= rand()%dimension + 1; //la reina ubicada en la primera columna está en la fila aleatoria
 for (int i = 2; i <= dimension; i++)
 {
    int k = 0;
    bool amenazada = true;
    while (amenazada == true && k < 20 )
    {
        int fila_reina_iesima = rand()%dimension + 1;
        reina[i] = fila_reina_iesima;
        for (int j = 1; j<= i; j++)
        {
            IdentificadorReinas compara(fila_reina_iesima, reina[j], i, j);
            bool posicion_amenazada = compara.Amenaza();
            if (posicion_amenazada == true)
            {
                k++;
            }
        }
        if (k>0)
        {
            amenazada == true;
        }
    }
 }
 for (int i=1; i<= dimension; i++)
 {
     tablero[i][reina[i]] = 1;
 }
 for(int i=1; i<=dimension; i++)
 {
     for(int j=1; j<=dimension; j++)
     {
         cout<<tablero[i][j];
     }
     cout<<"\n";
 }
    
    return 0;
}
