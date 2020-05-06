/* punto 2: 
Por:Julian Andres Montoya Carvajal
c.c 1214727927
/*El problema del caballo en el ajedrez. ¿puede la pieza de ajedrez, conocida como caballo, moverse alrededor de un tablero de ajedrez vacío y tocar cada una de las 64 posiciones una y sólo una vez? Por favor desarrolle un algoritmo en c++ para estudiar este problema.*/

#include <iostream> //para utilizar cout 
#include <iomanip>
#include <string>//para utlizar cadenas de caracteres
#include <fstream> // flujo de archivo
#include <cstdlib>
#include <ctime>//libreria para random
#include <algorithm> //para poder utilizar algoritmos como el sor
#include <vector> //libreria para vectores
#include <cmath> //para funciones matematicas

using namespace std;

const int columnas=8;
const int filas=8;

void pasoL(int [],int); //prototipo de la funcion
void llenar(int [][columnas],int); //prototipo de la funcion
void desplegar(int [][columnas],int);//prototipo de la funcion

int main()
{

  srand(time(0));
  int tablero[filas][columnas]; //arreglo para tablero
  int L[2]; //arreglo para posibles movimientos del caballo, L[0] horizontal y L[1] vertical
  int posini=1;
  tablero[0][0]=posini; //se define la posicion incial
  int paso=1; //indica numero de pasos -1 que ha dado el caballo
  int fila=0; //indica posicion de fila en el arreglo T
  int col=0; //indica posicion de columna en arreglo T
  int s=0; //s=0 indica movimiento invalido, s=1 mov. valido
  int cuenta=0; //parametro para reiniciar el intento

  while(paso<64) 
    {
      s=0;
      while(s==0) //ciclo para saber si el movimiento es valido
	{
	  cuenta++;
	  if(cuenta==50) //el camino tomado no fue solucion, reinicia
	    {
	      llenar(tablero,filas);
	      
	      cuenta=0; //reinicia todos los valores
	      paso=1;
	      fila=0;
	      col=0;
	      tablero[fila][col]=posini;
	    }
	  pasoL(L,2); //generamos movimiento en L aleatorio
	  if(L[0]+fila>=0 && L[0]+fila<=7 && L[1]+col>=0 && L[1]+col<=7 && tablero[fila+L[0]][col+L[1]]==0) //Condicion de que el movimiento se encuentre adentro del tablero y sin repeticion
	    {
	      fila=fila+L[0]; //cambio de poiscion en fila
	      col=col+L[1]; //cambio de posicion en columna
	      tablero[fila][col]=paso+1; //marca el paso en el tablero
	      s=1;
	      cuenta=0;
	    }
	}
      paso=paso+1;
      
    }

  
  desplegar(tablero,filas);

  return 0;
}

void pasoL(int L[], int p=2)
{
  int n; 
  n=1+rand()%8;
  //son en total 8 posibles movimientos que tiene el caballo 

  switch(n)
    {
    case 1:
      L[0]=2;
      L[1]=-1;
      break;
    case 2:
      L[0]=2;
      L[1]=1;
      break;
    case 3:
      L[0]=1;
      L[1]=2;
      break;
    case 4:
      L[0]=-1;
      L[1]=2;
      break;
    case 5:
      L[0]=-2;
      L[1]=1;
      break;
    case 6:
      L[0]=-2;
      L[1]=-1;
      break;
    case 7: 
      L[0]=-1;
      L[1]=-2;
      break;
    case 8:
      L[0]=1;
      L[1]=-2;
      break;
    }
  
}

void llenar(int arrebi[][columnas], int filas)//llenar tablero de elementos ceros
{
  for(int i=0;i<filas;i++)
    {     
      for(int j=0;j<columnas;j++)
	{
	  arrebi[i][j]=0; 
	}
    }
}

void desplegar(int arrebi[][columnas], int filas) //imprimir tablero
{
  for(int i=0;i<filas;i++)
    {
      
      for(int j=0;j<columnas;j++)
	{
	  cout << setw(4) << arrebi[i][j]; 
	}
      cout << endl;
    }

}
