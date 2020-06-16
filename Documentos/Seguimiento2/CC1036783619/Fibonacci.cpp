//Sucesion de fibonacci

#include<iostream>
 using namespace std;
 
 int main(){
	int n, i;
	cout<<"Ingrese cantidad de numeros de fibonacci a calcular: "; cin>>n;
	int f[n]; //crea el arreglo de dimensión n			
	f[0]=0; //son los primeros dos términos
    f[1]=1;

    for(i=2;i<n;i++){ //asigna a cada elemento del arreglo un valor 
        f[i]=f[i-1]+f[i-2];	
	}
	

    for (i=0;i<n;i++){ //imprime los n numeros de fibonacci
    	cout<<f[i]<<endl;
	}
        
 	
 	return 0;
 }
