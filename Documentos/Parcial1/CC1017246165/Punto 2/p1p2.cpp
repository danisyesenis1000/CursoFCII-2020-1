#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdlib.h>
#include<time.h>

using namespace std;


//Esta es la función que nos va a calcular los numeros perfectos
void perf(int numero){
  int perfecto,divisor,divisores;
  perfecto=0;
  for(int i=1;i<numero;i++){
    divisor= (numero%i);
    if(divisor==0){
      perfecto=perfecto+i;
    }
  }
  if(numero==perfecto){
      cout<<numero<<" es un numero perfecto"<<endl;
       cout<<"con divisores\n";
      for(int j=1;j<perfecto;j++){
	divisores=(perfecto%j);
	  if(divisores==0){
	    cout<<setw(5)<<j;
	  }
      }
      cout<<endl;
  }
}

int main(){
  int numero1;
  cout<<"Bienvenido a un calculador de números perfectos, si su numero es perfecto el programa se lo dirá"<<endl;
  cout<<"Calculo de numero perfecto para entero que usted ingrese"<<endl;
  cout<<"Ingrese un numero entero cualquiera"<<endl;
  cin>>numero1;
  perf(numero1);

  cout<<"Calculo de numero perfecto para los primeros números del 1 al 10000"<<endl;
  const int TL=10000; //Tamaño de los numeros
  for (int j=1;j<=TL;j++){
    perf(j);
  }
  return 0;
}
