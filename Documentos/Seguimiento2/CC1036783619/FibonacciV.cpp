//Sucesion de fibonacci

#include<iostream>
#include<vector>
 using namespace std;
 
 int main(){
	int n, i;
	cout<<"Ingrese cantidad de numeros de fibonacci a calcular: "; cin>>n;
	vector<int>f; //crea el vector 		
	f.push_back(0); //son los primeros dos términos
    f.push_back(1);

    for(i=2;i<n;i++){ //agrega al final del vector el siguiente término de la sucesioón
        f.push_back(f[i-1]+f[i-2]);	
	}

    for (i=0;i<n;i++){ //imprime los n numeros de fibonacci
    	cout<<f[i]<<endl;
	}
        
 	
 	return 0;
 }
