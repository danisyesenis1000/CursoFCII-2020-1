#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void Fibonacci_arreglo(int n_elem)
{
  cout<<"La lista de los primeros "<<n_elem<< " números de Fibonacci, empleando arreglos es: "<<endl;
  unsigned long int Arr[n_elem];
  Arr[0] = 0;  //Definimos los primeros dos numeros de Fibonacci
  Arr[1] = 1;
  cout<< Arr[0]<< setw(3)<< Arr[1]<< setw(3);
  for (int i=2; i< n_elem; i++)
    {
      Arr[i] = Arr[i-1] + Arr[i-2];
      cout<<"  "<<Arr[i];
    }
  cout<<"\n";
}

void Fibonacci_vector(int n_elem)
{
  cout<<"El VECTOR con los primeros "<<n_elem<<" números de Fibonacci es:"<<endl;
  vector <unsigned long int> fibonachi(2);   //inicialmente el vector tiene 2 entradas
  fibonachi[0]= 0;
  fibonachi[1]= 1;
  cout<< fibonachi[0]<< setw(3)<< fibonachi[1]<< setw(3);
  for (int i=2; i<n_elem; i++)
    {
      fibonachi.push_back(fibonachi[i-1]+fibonachi[i-2]); //en este caso, push_back agrega al final del vector el valor que corresponde a la suma de las entradas i-1 e i-2 del vector 
	cout<<"  "<< fibonachi[i];
    }
  cout<<"\n";
}

int main()
{
  int N;
  cout<<"Ingrese el número de elementos de la sucesión de Fibonacci que desea obtener"<<endl;
  cin>> N;
  if(N==0) return 0;
  if(N==1)
    {
      cout<<"El primer elemento de la sucesión de Fibonacci es 0, intente otro número"<<endl;
      return 0;
    }
  Fibonacci_arreglo(N);
  Fibonacci_vector(N);
  return 0;
}
