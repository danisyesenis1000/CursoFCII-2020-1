#include <iostream>
#include <stdlib.h>
#include <math.h>  

using namespace std;

bool perfecto(int numero){
	int sum=0;

		for (int j=1;j<numero;j++){
			float intpart;
  			if(modf(float(numero)/float(j),&intpart)==0)
  				sum+=j;
		}
		
		if(sum==numero)
			return 1;
		else
			return 0;
}

int main(){
	cout<<"Lista de numeros perfectos del 1 al 10000 y sus divisores:"<<endl;
	
	for (int i=1;i<10000;i++){

		if(perfecto(i)){
			cout<<i<<"=1";

			for (int j=2;j<i;j++){
				float intpart;
  				if(modf(float(i)/float(j),&intpart)==0)
  					cout<<"+"<<j;
			}
			cout<<endl;
		}
	}
}