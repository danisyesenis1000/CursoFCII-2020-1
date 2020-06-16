#include <iostream>
#include <iomanip> //Importamos las librerias necesarias
#include<cmath>

using namespace std; 


int movimientoDeCaballo(int,int,int,int (*)[8],int*,int*); //Definimos el prototipo de la funcion " movimientoDeCaballo", le entran enteron y arreglos. esta fucnion me permite hacer los movimientos del Caballo
bool rangodeMatriz(int,int,int(*)[8]);//definimos el prototipo de la funcion"rangodeMatriz", le entran enteros y arreglos, esta funcion analiza si el movimiento del caballo esta dentro de la matriz

#define fila 8 //definimos fila como una variable global
#define columna 8 //definimos columna como una variabel global
int matriz[fila][columna]={0};  //hacemos un arreglo de 8 x 8 llena de ceros

int main() {
  cout<<"\n"<<endl;
  cout<<"\t\t  ==========================="<<endl;
  cout<<"\t\t ||      CABALLO AJEDREZ     ||"<<endl;
  cout<<"\t\t  ===========================\n"<<endl;
  int conta=1; //inicializamos un contador en 1
  int cFila[8] = {2,1,-1,-2,-2,-1,1,2}; 
  int cColumna[8] ={1,2,2,1,-1,-2,-2,-1}; //Estos dos arreglos son las posibles combinaciones de movimientos que puede tener un caballo de ajedrez en un posicion dada. Esto se utiliza para realizar todo el recorrido. 
  matriz[0][0]  = conta; // llenamos la posicion {0,0} de a matriz con un 1

  if(movimientoDeCaballo(0, 0, conta+1, matriz, cFila, cColumna) == false) { // evalua la funcion movimiento caballo, con la posicion de entreada {0,0}
      return false;
   }
   else
     {
       for(int i=0;i<fila;i++) // se imprime la matriz del resultado.(filas)
	{
	  for(int j=0;j<columna;j++)// imprime la matriz, cuenta sobre las columnas
	    {
	      cout<<matriz[i][j]<<"\t";
	    }
	  cout<<"\n"<<endl;    
         }
     }
     
   return 0; // fin de funcion main
}

// funcion en la que el caballo hace los movimientos
int movimientoDeCaballo(int mf, int mc, int contador, int matriz[fila][columna], int cFila[fila], int cColumna[columna]) {
  
  int nFila; //definimos una variable para almacenar el valor de la fila
  int nColumna; //definimos una variable para almacenar el valor de una columna
  if (contador == fila*columna) //acaba cuando el contador es 64    
      return true;

   for (int j = 0;j < 8; j++) {
     nFila = mf + cFila[j]; //hacemos los movimientos teniendo el cuenta los arrglos cFila
     nColumna = mc + cColumna[j];// haccemos los movimientos teniendo en cuenta el arreglo cColumna
     if (rangodeMatriz(nFila, nColumna, matriz)) { //vemos si la posicion anterior esta dentro de la matriz
       matriz[nFila][nColumna] = contador; // llenamos la posicion con el valor del contador
       if (movimientoDeCaballo(nFila, nColumna, contador+1, matriz, cFila, cColumna) == true)// se evalua si la siguiente posicion esta permitida en la funcion
	 return true;// regresa una verdad
         else
	   matriz[nFila][nColumna] = 0; //si no se puede deja el valor de la posicion como antes, en un cero.
      }
   }
   return false;
}

bool rangodeMatriz(int mf, int mc, int matriz[fila][columna]) {// funcion para  sabes si no se salio del arreglo de matriz
  return ( mf >= 0 && mf < fila && mc >= 0 && mc < columna && matriz[mf][mc] == 0);//condiciones para el la posicion este dentro de la matriz
}
