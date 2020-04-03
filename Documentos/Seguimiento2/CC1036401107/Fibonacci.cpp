#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// Funciones prototipo.

void Fibonacci1(int[],int );      // Serie de Fibonacci por arreglos.
void Fibonacci2(vector< int > &); // Serie de Fibonacci por vectores.

// Funcion principal

int main()
{
  int n = 10;          // Número de terminos de la serie para el arreglo.  
  vector< int > serie(10);   //Número de términos para el vector.
  int a[n] = {0,1,2,3,4,5,6,7,8,9};  //Arreglo inicial que luego va a ser cambiado por la serie.

  Fibonacci1(a,n);

  cout << "Los valores de la serie de Fibonacci por arreglos son:\n";
  
  for (int j= 0; j< n; j++)           // Se llena el arreglo llamando a la funcion Fibonacci1
    cout << setw( 3 ) << a[j] << " ";

  cout << endl;

  Fibonacci2(serie);

  cout << "Los valores de la serie de Fibonacci por vectores son:\n";

  std::vector<int>::const_iterator lit(serie.begin()), lend(serie.end());  // Esta es la forma en que se llena el vector llamando la 
  for(;lit != lend;++lit)                                                  // función Fibonacci2
    {
      cout << setw( 3 ) << *lit << " ";
    }
  cout << endl;

    
  return 0;    
}

void Fibonacci1(int a[],int n)
{
  int n1 = 0;
  int n2 = 1;
  int n3;
  

  for (int i=2;i<n;i++)
    {
      n3 = n1 + n2;
      a[i] = n3;       
      n1 = n2;
      n2 = n3;
    }
}

void Fibonacci2( vector< int >&arreglo)
{
  size_t i;
  int n1 = 0;
  int n2 = 1;
  int n3;

  arreglo.clear();
  arreglo.push_back( n1 );    //Se le ingresan los dos primeros numeros 0 y 1
  arreglo.push_back( n2 );

  for (i = 2; i< 10; i++)
    {
      n3 = n2 + n1; 
      n1 = n2;
      n2 = n3;
      arreglo.push_back(n3);    // Se le van ingresando los nuevos números de la serie.
    }
}
