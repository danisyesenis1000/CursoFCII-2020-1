#include <stdlib.h> // importamos las librerias necesarias
#include <time.h>
#include<iostream>
using namespace std;

int main() // inicio de la funcion main
{
  
  srand(time(NULL));//es la semilla para inicializar los numeros aleatorios
  int numero;
  int valor;
  int llave=0;
  int seguir=0;
  cout<<"===========Adivinar el Numero================"<<endl;
  cout<<"-Ingresar un numero entre 1 y 1000"<<endl;
  numero=1+rand()%(1000); //numero aleatorio entre 1 y 6

  while(llave==0)
    {
      cout<<"-------------"<<endl;
      cout<<"Ingresa valor="; // se piede ingresar un valor 
      cin>>valor;  // asigna un valor
      if(numero<valor){  // se compara si el numeor es menor

	cout<<"El número que busca es menor"<<endl;
	
      }

      else if(numero>valor) // se compara si el numero es mayor
	{
	  cout<<"El número que busca es mayor"<<endl;
	}
      else
	{
	   cout<<"Gano\n********************"<<endl;
	   cout<<"Desea seguir jugando?. Si=0; No=1 "<<endl; // elige si desea seguir jugando
	   cout<<"Opcion=";
	   cin>>seguir;

	   if(seguir==0) //sigue jugando
	     {
	       numero=1+rand()%(1000);
	       
	       cout<<"=================\nEl juego sigue"<<endl;
	     
	       llave=0;
	     }

	   else // no sigue el juego
	     {
	       cout<<"El juego no sigue"<<endl;
	       llave=1;
	     }
	   
	}
    }
  
  cout<<"========================\nFinal del juego.\n======================="<<endl;

  return 0; // termina la funcion main

}
