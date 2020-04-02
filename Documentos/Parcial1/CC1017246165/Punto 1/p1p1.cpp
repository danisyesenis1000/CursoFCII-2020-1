#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main(){
  int jugando,numero,NumeroSupuesto,NumeroCorrecto;
  do{
    cout<<"Bienvenido al juego de adivinar el número"<<endl;
    // Crea numeros aleatorios
    srand(time(NULL));
    NumeroCorrecto=1+rand()%(1001-1); //Rango propuesto

    //Estructura del juego
    do{
      cout<<"Ingrese un numero entre 1 y 1000 que sea entero: "; //Usuario ingresa valor
      cin>>NumeroSupuesto;
      if(NumeroSupuesto>1000 || NumeroSupuesto<1){
	cout<<"Recuerde, su número debe ser entero y estar entre 1 y 1000"<<endl;
      }
      else{
	if(NumeroSupuesto==NumeroCorrecto){  //Programa verifica y asigna valor a una variable
	  numero=1;
	}
	if(NumeroSupuesto<NumeroCorrecto){
	  numero=2;
	}
	if(NumeroSupuesto>NumeroCorrecto){
	  numero=3;
	}
	switch(numero){
	case 1: cout<<"El número proporcionado es el correcto"<< endl; //Cada caso
	  break;
	case 2: cout<<"El numero es menor al correcto"<<endl;
	  cout<<"Digite otro numero"<<endl;
	  break;
	case 3: cout<<"El numero es mayor al correcto"<<endl;
	  cout<<"Digite otro numero"<<endl;
	  break;
	}
      }
    }while(NumeroSupuesto !=NumeroCorrecto);
    cout<<"¿Desea seguir jugando a adivinar el número? De ser así digite el número uno (1) y presione enter, de lo contrario digite una tecla distinta al número  uno (1) y oprima enter ";
    cin>>jugando;
  }while(jugando==1);
  return 0;
}
