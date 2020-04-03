#include <iostream>
using namespace std;

int perfecto(int numero){ //Funcion que determina numero perfecto, retorna 0 si no lo es, retorna el numero si lo es
	int a=0; //es el primer divisor, cero
	for (int i=1;i<numero;i=i+1){
		if (numero%i==0){ //si el modulo es cero, es divisor
			a=a+i; //la suma acumulativa de los divisores
		}
	}
	if(numero==a){ //si la suma de los divisores es el numero, retorna el numero porque es perfecto
		return numero;
	}
	else{ //en caso contrario retorna un valor nulo
		return 0; 
	}
	
}

int main(){
	cout<< "Lista de los numeros perfectos menores a 10000"<<endl;
	int i=6; 	//se parte del primer numero perfecto
	while (i<=10000){ 	//condicion para los primeros 10000 numeros perfectos
		if (perfecto(i)!=0){ 	//si es perfecto lo imprime en pantalla
			cout<<"El numero perfecto es:  "<<perfecto(i)<<endl;	
			cout <<"Sus divisores son:"<<endl;
			int b=0;
			for (int j=1;j<perfecto(i);j=j+1){  //algoritmo para imprimir los divisores
				if (perfecto(i)%j==0){
					b=b+j;
					cout<<b<<endl;
				}
			}
		}
		i=i+1;
	}
	return 0;
}


