#include<iostream> // importamos la librerias necesarias
#include<iomanip>
#include<cmath>

using namespace std;

string perfecto(int);// definimos el prototipo de la funcion perfecto
int main() //inicio de main()
{

  cout<<"====Número perfecto==\n"<<endl;
  for (int j=1;j<=10000;j++) // ciclo para encontrar el numero perfecto de 1 10000
    {
      if(perfecto(j)=="Es perfecto") // llamara a la funcion perfecto y comparar
	{
	  cout<<" "<<endl;
	}
      else
	{
	  continue;
	}
    }
  return 0; // final de main

}


string perfecto(int numero) //funcion perfecto
{
  int perfe=0;
  string s;
  for(int i=1; i<numero;i++)
    {
      if((numero%i)==0) // compara si es dividio por el numero
	{
	  perfe=perfe+i; //suma de los divisores del numero 
	}
      else
	{
	  continue;
	}
      
    }

  if(perfe==numero) // compara si es un numero perfecto
    {
      cout<<"El numero "<<perfe<<" es perfecto y sus divisores son:"<<endl;
      for(int i=1;i<perfe;i++) // imprimir los diisores
	{
	  
	  if((perfe%i)==0) // compara si es dividio por el numero
	    {
	      cout<<i<<endl; //suma de los divisores del numero 
	    }
	  else
	    {
	      continue;
	      }
	  
	 }
      cout<<"=========================="<<endl;
       s="Es perfecto";
    }

  else
    {
      s="No es perfecto";
    }

  return s; // retorna si es numero perfecto
    
}
