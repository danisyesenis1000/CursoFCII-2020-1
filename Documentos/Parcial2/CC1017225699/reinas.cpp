#include <string>
#include <stdbool.h> 
#include <stdio.h> 

#include <iostream>
using namespace std;

#include "reinas.h"


reinas::reinas(int N)
{
    setdim(N);
        
}

void reinas::setdim(int N)
{
    D=N;
}



void reinas::printtablero(int tablero[8][8], int N) 
{ 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++)
        {
            cout << tablero[i][j]<<" ";
        }        
        cout <<"\n"; 
    }
    cout << endl; 
} 
  
/* funcion para averiguar si una reina esta a salvo en el tablero */



bool reinas::Psegura(int tablero[8][8],int N, int row, int col) 
{ 
    int i, j; 
  
    /* verificar esta fila a la izquierda*/
    for (i = 0; i < col; i++)
    { 
        if (tablero[row][i])
        { 
            return false;
        } 
    }
  
    /* verificar la diagonal superior izquierda*/
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    { 
        if (tablero[i][j])
        { 
            return false; 
        }    
    }


    /* verificar la diagonal inferior izquierda */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
    { 
        if (tablero[i][j])
        { 
            return false; 
        }
    }    
    return true; 
} 
  





bool reinas::solRecu(int tablero[8][8],int N, int col) 
{ 
    /* si todas la reinas han sido colocadas*/
    if (col >= N) 
        return true; 
  
    /* para esta columna pruebe todas las filas*/
    for (int i = 0; i < N; i++)
    { 
        
        /* ver si una reina se puede colocar en  
          tablero[i][col] */
        if (Psegura(tablero,N, i, col)) 
        { 
            /* poner a la reina en tablero[i][col] */
            tablero[i][col] = 1; 
  
            /* de manera recursiva verificar si las demas reinas se pueden colocar */
            if (solRecu(tablero,N, col + 1))
            { 
                return true; 
            }
            
            /* si no hay solucion para las demas reinas quitar reina de tablero[i][col] */
            tablero[i][col] = 0; // BACKTRACK 
        } 
    } 
  
    /* si la reina no se puede colocar en ninguna fila*/
    return false; 
} 
  


bool reinas::solR() 
{ 
    int tablero[8][8] = {}; 
    
    if (solRecu(tablero,D, 0) == false) { 
        printf("no hay solucion"); 
        return false; 
    } 
  
    printtablero(tablero,D); 
    return true; 
} 
