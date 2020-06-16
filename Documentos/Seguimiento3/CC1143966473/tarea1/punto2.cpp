#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

void lectura_archivo(ifstream *); // se hace el prototipo de la funcion lectura_archivo

int main()
{
  string name("datos.dat");
  ifstream entradas;
  entradas.open(name.c_str());
  lectura_archivo(&entradas);
  return 0;
}

void lectura_archivo(ifstream *entrada) // se llama la funcion lectrua_archivo
{
  
  if(entrada->fail()) //prueba si existe
    {
      cout<<"Error al abrir archivo"<<endl;
      exit(1);
    }
  // se definen variables
  char nombre[ 30 ];
  char numeroseguro[30];   
  float tarifahora;
  float horastrabajadas;
  cout<<"\nNomina:"<<endl;
  cout<<"Seguro\t\tNombre\t\tPago Bruto"<<endl;
  // se hace lectura de los archivos y se hace la multiplicacion
  // de las dos columnas
  while(*entrada>>nombre>>numeroseguro>>tarifahora>>horastrabajadas)
    {
      // se imprimen los valores
      cout<<numeroseguro<<"\t"<<nombre<<"\t"<<(tarifahora*horastrabajadas)<<endl;
    };
  
}
