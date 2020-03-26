#include <iostream>
using namespace std; //espacio de nombres
#include <iomanip> //para los manipuladores
#include <cmath> //para funciones matematicas
#include <stdlib.h> //contiene los prototipos para las funciones srand y rand
#include <time.h> //para numeros aleatorios

//en el siguiente codigo se encuentra desarrollado el punto 1 y punto 2 del parcial
// por Julian Andres Montoya
//c.c 1214727927

void perfecto(int z);//prototipo de funcion que calcula si un numero es perfecto

int main()
{
  srand(time(NULL));
  int x=0; //inicializo el numero a ingresar para evitar inconvenientes
  int num;
  num= 1 + rand()%(1000+1-1);//genero un numero aleatorio entre 1 y 1000
  
  while(x!=num) //mientras x sea diferente del numero aleatorio el while se ejecuta
    {
      cout << "Por favor escoja un numero del 1 al 1000" << endl;
      cin>>x;
      cout << "El numero escogido es: " << x << endl;
      
      //cout << "El numero generado es: "<< num << endl;
      if (x!=num && x<num)
	{
	  cout <<"Su elecccion es menor que el numero generado." << endl;
	}
      else if(x!=num && x>num)
	{
	  cout <<"Su elecccion es mayor que el numero generado." << endl;	
	}
      else if(x==num)//si acerto preguntar si desea seguir jugando o terminar juego
	{
	  cout << "Has acertado." << endl;
	  cout << "Ingrese 1 para continuar jugando o 0 para terminar." << endl;
	  int y;
	  cin>>y;
	  if(y==0)
	    {
	      cout << "El juego ha terminado." << endl;
	    }
	  else if(y==1)
	    {
	      cout << "Continuamos jugando." << endl;
	      x=0; //inicializo el numero a igresar para evitar inconvenientes
	      num= 1 + rand()%(1000+1-1); //vuelvo y genero un numero aleatorio entre 1 y 1000	      
	    }
	}    
    }
  
  //numeros perfectos
  cout << "numeros perfectos" << endl;

  for(int j=1;j<10001; j++) //calculo los numeros perfectos entre 1 y 1000
    {
      perfecto(j); //llamo la funcion para cada j entre 1 y 1000
    }

  return 0;
}

//funcion de numeros perfectos
void perfecto(int z)
{
  int suma=0;//inicia suma en 0 
  int comp;
  for(int i=1; i<z; i++)
    {
      if(z%i==0)
	{
	  suma=suma+i; //va sumando los divisores del numero
	  comp=suma;
	}
    }
  
  if(comp==z)
    {
      cout << z << " es un numero perfecto" << endl;
      for(int i=1; i<z; i++)
	{
	  if(z%i==0)
	    {
	      cout << z << " es divisible por " << i << endl;
	    }
	}
    }
  
}
