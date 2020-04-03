#include <iostream>
using namespace std;


void Perfecto(int);   // Función prototipo.

int main()   // Función principal.
{
  cout << "Números perfectos entre 1 y 10000" << endl;

  for(int n=1; n<10000; n++)   // Ciclo que corre entre 1 y 10000 para encontrar los números perfectos
    Perfecto(n);

  return 0;
}

void Perfecto(int numero)
{
  int j;            // Contador que corre sobre los divisores
  int suma = 0;     // suma todos los numeros que son divisores

  for (j=1; j < numero; j++)
    {
      if (numero % j == 0)   // Si el numero es divisor entonces sumelo
	suma += j;
    }
  if (suma == numero)    // Si la suma de los divisores es igual a el numero, entonces es un numero perfecto
    {
      cout << "\n" << numero << " Es un número perfecto y sus divisores son: "; 
      for (int i =1; i<numero;i++)  // Se hace el ciclo para imprimir los divisores así: 6 = 1+2+3 sin incluir el mismo numero.
      {
      if (numero%i == 0 && numero != i)
	cout << i << "+";
  
      }
    }
}
  
