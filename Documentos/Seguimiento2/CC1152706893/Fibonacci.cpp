//Serie de Fibonacci usando arreglos

#include <iostream>
#include <cstdlib>
using namespace std;
 
int main(){
 
    int i, n, cont = 0;
    long long int a[100];
 
    a[0] = 0;
    a[1] = 1;
 
    cout << "Introduzca el numero de terminos de la serie:  ";
    cin >> n;
    cout << "Los " << n << " primeros numeros de la serie de Fibonacci son: " << endl;
 
    for(i=1; i < n; i++){
        a[i+1] = a[i-1] + a[i];
    }
 
    for(i=0; i < n; i++){
        if (cont == 10){ 
            cont = 0;           
        }
        cout <<  a[i] << " ";
        cont += 1;  
 
    }
}
