#include <iostream>
#include <iomanip>
using namespace std;

int perfecto(int numero)
{
  int SumDiv = 0;
  for (int i=1; i<=numero/2; i=i+1) //solo hago la búsqueda hasta la mitad del número, porque este no tendrá nunca  divisores mayores a éste, lo que nos ahorrará tiempo de cómputo en caso de tener listas muy largas de números perfectos.(además obtendremos un entero ya que no se han encontrado numeros perfectos impares) 
    {
      if (numero%i==0) //Si el número es divisible por cada valor del contador i, agrego ese valor de i a la sumatoria de los divisores anteriores
	{
	  SumDiv = SumDiv + i;
	}
	}
  if(numero == SumDiv)
    {
      return numero;
    }
  else
    {
      return 0; 
    }	
}

int main()
{
  cout<< "Números perfectos menores a 10000 y sus divisores:"<<endl;
  int i=6; 	//Primer numero perfecto
  while (i<=10000)
    {
      if (perfecto(i)!=0)
	{
	  cout<<"\nNúmero perfecto:  "<< i <<endl; //todo lo hago con "i" y no con perfecto(i) porque ya se que solo voy a tener los "i" correspondientes a números perfectos gracias al condicional
	  
	  cout <<"Divisores:"<<endl;
	  for (int j=1; j < i; j=j+1)
	    {
	      if (i%j==0)
		{
		  cout<<setw(4)<<j<<endl;
		}
	    }
	}
      i=i+1;
    }
  return 0;
}
