//aqui se programa la seie aritmética a+(a+b)+(a+2*b)+...+(a+(n-1)*b solo hasta el termino 100
#include <iostream>
using namespace std;

int main(){
	int a=1, d=3, n=100;// se ponen los terminos definidios por el ejercicio. como a como el primer termino, d=diferencia común y n el numero de terminos que se sumaran. 
	int i=0, b=0, f;//i inicializado en 0, es el contador que tendra como centinela a n=100, por tanto n limita los terminos y sumas que se harán. 
	//f son los terminos que tendra la suma y b es el acomulador de los terminos sumados inicializado en 0  
	while(i<n){ //inicio del ciclo
		f=a+(i*d); //definición de cada termino
		b=b+f;//suma ó acomulació de los terminos 
		++i;//incremento de 1 a i 
		cout<<"El termino "<<i<<" es "<<f<<" con el acomulado "<<b<<endl;
	}//fin del ciclo 
	cout<<"La suma de la serie aritmética es: "<<b<<endl;
	return 0; 
}
		
	
	
