#include <iostream> //Importamos las librerias necesarias
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void array_fibo(int); // prototipo de la funcion array_fibo
void vector_fibo(int); // prottoitpo de la funcion vector_fibo


int main() // inicimos la funiona main
{
  int terminos;
  cout<<"======Sucesión de Fibonacci========="<<endl;
  cout<<"Ingresar el numero de teminos que desea imprimir=";
  cin>>terminos;  // asignamos el numero de terminos a imprimir
  cout<<"\n============================"<<endl;
  cout<<"Serie de Fibonacci con arreglos"<<endl;
  array_fibo(terminos); // llamamos la funcion array_fibo
  cout<<"============================"<<endl;
  cout<<"Serie de Fibonacci con Vector"<<endl;
  vector_fibo(terminos); // llamanos la funcion vector_fibo
  cout<<"Final"<<endl;
  return 0;
}


void array_fibo(int numero) // definimos el funcion array_fibo
{
  double arreglo[numero]; //se define un arreglo con un numero de elementos
  arreglo[0]=0; // llenamos la dos primeros terminos del arreglo
  arreglo[1]=1;
  // condiciones de los dos primeros arreglos
  if (numero==0){cout<<"\nNingun termino a imprimir, cero terminos";}
  else if(numero==1){cout<<"->1 termino\n"<<arreglo[0];}
  //imprimer y llevar el arreglo
  else
    {
      cout<<"->"<<numero<<" terminos\n"<<arreglo[0]<<"-"<<arreglo[1];
      for(int i=1; i < numero-1; i++)
	{
	  arreglo[i+1] = arreglo[i-1] + arreglo[i];
	  cout<<"-"<<arreglo[i+1];
	}
    }
  cout<<"\n"<<endl;
}


void vector_fibo(int numero) // se define la funcion vector_fibo
{
  vector< int > vector(numero+1); // defnimos el vector

  vector[0]=0; // llenamos los dos primeros terminos del vector
  vector[1]=1;

  // ccoondiciones de los dos primeros terminos
  if (numero==0){cout<<"\nNingun termino a imprimir, cero teminos";}
  else if(numero==1){cout<<"->1 termino\n"<<vector[0];}
  // imprimir y llenar el vector
  else
    {
      cout<<"->"<<numero<<" terminos\n"<<vector[0]<<"-"<<vector[1];
      for(int i=1; i < numero-1; i++)
	{
	  vector[i+1] = vector[i-1] + vector[i];
	  cout<<"-"<<vector[i+1];
	}
    }
  cout<<"\n"<<endl;
}
