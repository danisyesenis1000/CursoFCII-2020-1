#include <iostream>
#include <cmath>
#include "file.h"


//para resolver el ejercicio consideramos de que cada reina va en una cola columna, por lo tanto solo debemos analizar las filas y la diagonal, para analizar la diagonal miramos si la distancia entre las dos reinas es la misma y para mirar la fila comprobasmos esta por medio de una igualdad 


using namespace std;
reinas::reinas(int num)
{
  n=num;
}
bool reinas::distancia(int a, int b)
{
  return abs(a-b);//para comprobar si esta en la diagonal 
}

bool reinas::validar(int array[],int l)
{
  for(int i=0;i<l-1;i++)
    {
      if ((array[i]==array[l]) or (distancia(array[i],array[l])==distancia(i,l)))
	{ //comprueba si esta en la diagonal o si esta en la misma  fila 
	  return false;
	}
    }
  return true;
}
		       
//Funcion que va colocando a las reinas en un orden 
bool reinas::funcion(int array[],int etapa)
{
  bool funciono;
  if (etapa>n)
    {
      //break;
    }
  else
    {
    funciono = false; //como no ha funcionado el programa lo colocamos en false
    array[etapa]=-1; //comenzamos en una etapa imaginaria -1 donde no se ha colocado ninguna reina 
    while (funciono!=true) //siempre que funciono sea diferente de verdadero 
      {
	for(int i=0;i<n;i++){
	  
	  array[etapa]=array[etapa]+1;
	  //cout<<array[etapa]<<" "<<etapa<<endl;
	  if (validar(array,etapa))
	    {
	      if (etapa<n)
		{
		  funciono=funcion(array,etapa+1);
		}
	      else
		{
		  funciono =true;
		}
	    }
	}
      }

    }
  return funciono;
}
void reinas::ejecucion()
{
  int pos[n];
  funcion(pos,0);

  //cout<<pos<<endl;
}
      
      
  
