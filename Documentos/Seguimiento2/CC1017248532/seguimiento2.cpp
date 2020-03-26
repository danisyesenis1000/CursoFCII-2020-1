#include <iostream>
#include <vector>

using namespace std;
/*
Para las funciones se hará la excepción de no usar arrays o vectores en los primeros dos elementos de la serie
pues estos son necesarios para realizar la recurrencia. Por ello se inicializaran en 0 y 1 respectivamente,
y cuando el usuario pida alguno de ellos, simplemente se devolverá 0 ó 1.
*/

int Fibonacci_Array(int);
int Fibonacci_Vector(int);

int main(){
  int element;
  int decision = 2;
  
  cout << "Ingrese el elemento de la serie que desea conocer: ";
  cin >> element;
  cout << endl;

  cout << "Escoja el método de cálculo que sea utilizar. 0: Array, 1: Vector." << endl;

  while(decision != 0 and decision != 1){
    
    cin >> decision;

    if (decision != 0 and decision != 1){
      cout << "Opcion incorrecta, vuelva a intentar." << endl;
    }
    
  }

  if (decision = 0){

    cout << "El elemento " << element << " de la serie es: " << Fibonacci_Array(element) << endl;
    }

  else if (decision = 1){

    cout << "El elemento " << element << " de la serie es: " << Fibonacci_Vector(element) << endl;
  }
  
  return 0;
}

int Fibonacci_Vector(int n){
  
  if (n == 0) return 0; 

  else if (n == 1) return 1;

  else {

    vector <int> v(n);

    v[0] = 0;
    v[1] = 1;

    for (int i = 2; i < n; i++){
      v[i] = v[i-2] + v[i-1];
    }

    return v.back();
  }
}

int Fibonacci_Array(int n){

  if (n == 0) return 0;

  else if (n == 1) return 1;

  else{
    
    int a[n] = {0,1}; //The first two elements in the series

    for (int i = 2; i < n; i++){

      a[i] = a[i-1] + a[i-2];
    }

    return a[n-1];
  }
}

int Fibonacci(int n){

  if (n == 0){
    return 0;
  }

  else if (n == 1){
    return 1;
  }

  else {
    return Fibonacci(n - 1) + Fibonacci(n - 2);
  }
}
