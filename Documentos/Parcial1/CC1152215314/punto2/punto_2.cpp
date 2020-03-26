#include <iostream>
#include <iomanip>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

#define SIZE 10000   //Hasta que numero iremos a mirar si es perfecto

//Prototipos de funciones
void perfecto(int);
void imprimir(int *,int);

int main()
{
  for(int i=2;i<SIZE;i++)
    {
      perfecto(i);           //Llamada a funcion perfecto
    }
  return 0;
}


void perfecto(int j)        //recibe el valor j y determina si es perfecto o no
{
  int acum=0;               //aqui voy a sumar todos los divisores para comparar con el numero j
  int contador=0;           //me va a servir para ir almacenando los divisores
  int divisores[SIZE]={0};  //aqui ire metiendo los divisores para poderlos imprimir (inicializa al resto en 0 por defecto)
  for(int h=j-1;h>0;h--)
    {
      if(j%h==0)            //condicion para ver si es divisor
	{
	  acum+=h;          //lo sumo a mi acumulador
	  *(divisores+contador)=h; //lo almaceno en mi arreglo de divisores
	  contador++;
	}
    }
  if(acum==j)               //Si el numero es perfecto entonces imprimalo
    imprimir(divisores,j);  //llamada a imprimir, le paso el arreglo (puntero) y el numero que fue perfecto
}

void imprimir(int *divisores,int j)
{
  int k=1;                                   //voy a recorrer el arreglo
  cout << j << " = " << *(divisores);        //imprimo el primer valor
  while(*(divisores+k)!=0)
    {
      cout << setw(2) << "+" << setw(2) << *(divisores+k);
      k++;
    }
  cout << endl;
}
