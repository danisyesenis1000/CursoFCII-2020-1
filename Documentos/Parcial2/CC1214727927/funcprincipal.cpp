/* punto 1
Por:Julian Andres Montoya Carvajal
c.c 1214727927
a)Diseñe una clase llamada "Circular" con los datos para el radio del circulo en el plano xy, la frecuencia angular de la particula que se mueve en el circulo, un pequeño intervalo de tiempo, el tiempo total que durara el movimiento del cuerpo, el numero de intervalos de tiempo tenidos en cuenta y una fase. Tambien deben aparecer el constructor y el destructor de la clase, las funciones miembros "xpos" y "ypos" que calculan las posiciones xy dado el tiempo. Las siguientes son las ecuaciones que debe codificar para xpos y ypos.

b) Ahora diseñe la clase "Expiral", que sera derivada de la clase Circular, para que herede el movimiento circular y adicione el movimiento en la direcion del eje z
*/

#include <iostream> //para utilizar cout 
#include <iomanip>
#include <string>//para utlizar cadenas de caracteres
#include <fstream> // flujo de archivo
#include <cstdlib>
#include <ctime>//libreria para random
#include <algorithm> //para poder utilizar algoritmos como el sor
#include <vector> //libreria para vectores
#include <cmath> //para funciones matematicas

#include "declaracion.h"
using namespace std;

const float pi=3.1416;

void desplegar(float [],int);//prototipo de funcion
void imprimir(float [],float [],float [], int); //prototipo de funcion

int main()
{
  float radio=1.0; //radio
  float frecu=4.0; //frecuencia
  float paso=0.1; //paso o intervalo de tiempo
  float Tf=1.0; //tiempo total
  int numsinter=(Tf+1.001*paso)/(paso); //numero de intervalos tenidos en cuenta
  cout << "numero de intervalos " << numsinter << endl;
  float alf=pi/2; //fase
  float arreglosxa[numsinter]; //arreglo donde estan las posiciones en x de a
  float arreglosya[numsinter]; //arreglo donde estan las posiciones en y de a

  //parta a

  Circular a(radio,frecu,paso,Tf,numsinter,alf); //creo un objeto a
  
  a.xpos(arreglosxa,numsinter); //aplico el metodo xpos al objeto a
  a.ypos(arreglosya,numsinter); //aplico el metodo ypos al objeto a

   cout << "Veamos valores x , y  del objeto a en columnas" << endl;
  
  cout << "veamos valores de x" << endl;
  desplegar(arreglosxa,numsinter); //imprimo valores de x del objeto a
  
  cout << "veamos valores de y" << endl;
  desplegar(arreglosya,numsinter); //imprimo valores de y del objeto a
  
  //parte b
  
  float zini=2;
  float velz=3;
  float arreglosze[numsinter]; //arreglo donde estan las posiciones en z de e
  float arreglosxe[numsinter]; //arreglo donde estan las posiciones en x de e
  float arreglosye[numsinter]; //arreglo donde estan las posiciones en y de e

  Espiral e(radio,frecu,paso,Tf,numsinter,alf,zini,velz); //creo un objeto e
  
  e.xpos(arreglosxe,numsinter); //aplico metodos de posicion al objeto e
  e.ypos(arreglosye,numsinter);
  e.zpos(arreglosze,numsinter);

  cout << endl;

  cout << "Veamos valores x , y y z del objeto e en columnas organizadas" << endl;
  cout << "valores de x";
  cout << setw(15) << "valores de y";
  cout << setw(15) <<"valores de z" << endl;
  imprimir(arreglosxe,arreglosye,arreglosze,numsinter); //imprimir columnas
   
  return 0;
}

void desplegar(float arreglo[],int numele) //funcion para imprimir arreglos
{
  for(int i=0; i<numele; i++)
    {
      cout  << fixed << setprecision(5) << arreglo[i] << endl;
    }

}

void imprimir(float arrx[],float arry[],float arrz[], int numele) //funcion para imprimir de manera ordenada en 3 columnas
{
  for(int i=0; i<numele; i++)
    {
      cout << fixed << setprecision(5) << arrx[i];
      cout << fixed << setprecision(5) << setw(15) << arry[i];
      cout << fixed << setprecision(5) << setw(15) << arrz[i] << endl;
    }
}
