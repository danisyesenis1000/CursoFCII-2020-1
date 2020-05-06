/*El siguiente codigo demuestra que un caballo puede recorrer las 64 casillas de un tablero de ajedrez pasando una única vez por cada una, el recorrido se inicia desde la casilla
(0,0) que se representa como la casilla superior izquierda del tablero, arroja una representación del tablero donde cada casilla se marca con el paso que dio el caballo en ella,
es decir la casilla (0,0) tiene el paso 0 y la casilla final tendría el paso 63, allí termina su recorrido el caballo*/

#include <iostream>
#include <iomanip>
using namespace std;

int tablero[8][8]; //define el tablero de ajedrez, una matriz 8x8
bool camino(int,int,int,int,int,int); //funcion que simula el camino que sigue el caballo a partir de (0,0)
bool recorrido(); //funcion que muestra el recorrido del caballo en el tablero

int main() {
   recorrido();

   return 0;
}

//Esta funcion simula el camino que sigue el caballo
bool camino(int x,int y,int NuCas,int tablero[8][8],int xM[8],int yM[8]) {
   int xm, ym; //estas variables representan las coordenadas horizontales y verticales que visita el caballo
   if (NuCas==64){  //cuando NuCas (el numero de casilla que visita el caballo) es igual a 64 quiere decir que se recorrió todo el tablero, devuelve un true    
      return true; 
   }
   else{ //si aún hay casillas disponibles, devuelve un false en caso de que no se puedan llenar todas
   for (int i=0; i<8; i++) {
      xm=x+xM[i]; //movimiento horizontal
      ym=y+yM[i]; //movimiento vertical
      if (xm>=0 && xm<8 && ym>=0 && ym<8 && tablero[xm][ym]==-1) {     //verifica que la casilla no haya sido ocupada y esté dentro del tablero
         tablero[xm][ym]=NuCas; //Marca la posición verifica con el numero de casilla (NuCas) en cada casilla del tablero, asignándole a la posición del tablero el paso que dio allí
         if (camino(xm, ym, NuCas+1, tablero, xM, yM)==true){ //si para el siguiente paso ya está lleno el tablero, se detiene 
            return true;
         } 
         else{ //si no está lleno el tablero se reinicia la operación, hasta que quede cada casilla haya sido visitada o ya no se pueda seguir el camino
            tablero[xm][ym]=-1;
    	 }
      }
    }
   }
   return false;
}

//Esta función muestra el recorrido del caballo en el tablero
bool recorrido() {     
   //Se marcan todas las casillas del tablero que no se han tocado por el caballo con un -1
   for (int x=0; x<8; x++){
      for (int y=0; y<8; y++){
         tablero[x][y]=-1;
       }
   }
   int xM[8]={2,1,-1,-2,-2,-1,1,2}; //posibles movimientos horizontales del caballo
   int yM[8]={1,2,2,1,-1,-2,-2,-1}; //posibles movimientos verticales del caballo, cada par coordenado es un movimiento completo del caballo
   tablero[0][0]=0;  
   if (camino(0,0,1,tablero,xM,yM)==true) { //cuando el caballo recorre todo el tablero, imprime las posiciones que recorrió en su respectivo orgen
   	  cout<<"El recorrido del caballo en el tablero es el siguiente"<<endl;
      cout<<"                                                      "<<endl;
   	  for (int x=0; x<8; x++) {
        for (int y=0; y<8; y++){
         cout<<setw(2)<<tablero[x][y]<<" ";
        }
      cout<<endl;
      }
   }
   return true;
}
