#include <iostream>
#include <iomanip>
#include <string>
//tarea2 seguimiento 2 por julian andres montoya
//c.c 1214727927
using namespace std;

void ejercicio10();
void ejercicio11();
void ejercicio12();


int main()
{
  ejercicio10();
  ejercicio11();
  ejercicio12();
  return 0;
}

void ejercicio10()
{
  string cadena;
  
  cout<<"porfavor ingrese el mensaje que desee\n";
  getline(cin, cadena);
  cout <<"el mensaje ingresado es: " << cadena << endl;
  
  int posicion = cadena.find( "e" );

  while ( posicion != string::npos )
    {
      cadena.replace( posicion, 1, "x" );
      posicion = cadena.find( "e", posicion + 1 );
    }
  
  cout <<"despues del reemplazo:\n" << cadena << endl;
}

void ejercicio11()
{
  string cadena2;
  
  cout<<"porfavor ingrese el mensaje que desee\n";
  getline(cin, cadena2);
  cout <<"el mensaje ingresado es: " << cadena2<< endl;
  
  string titular;
  string suplente;
  
  cout<<"ingrese la cadena que desea cambiar" << endl;
  getline(cin,titular);
  cout<<"lo que desea cambiar es: " << titular << endl;
  
  cout<<"ingrese el reemplazo" << endl;
  getline(cin,suplente);
  cout<<"el reemplazo es: " << suplente << endl;
  
  int tamanio=titular.length();
  cout<<"El tamaño de la cadena titular es: " << tamanio << endl;
  
  int posicion=cadena2.find(titular);
  cout<<"la posicion inicial del cambio es: " << posicion << endl;
  
  cadena2.replace(posicion, tamanio,suplente);
  
  cout <<"despues del reemplazo:\n" << cadena2 << endl;
}

void ejercicio12()
{
  string cadena3;
  
  cout<<"porfavor ingrese el mensaje que desee\n";
  getline(cin, cadena3);
  cout <<"el mensaje ingresado es: " << cadena3<< endl;
  
  string titular;
  string suplente;
  
  cout<<"ingrese la cadena que desea cambiar" << endl;
  getline(cin,titular);
  cout<<"lo que desea cambiar es: " << titular << endl;
  
  cout<<"ingrese el reemplazo" << endl;
  getline(cin,suplente);
  cout<<"el reemplazo es: " << suplente << endl;
  
  int tamanio=titular.length();
  cout<<"El tamaño de la cadena titular es: " << tamanio << endl;
  
  int posicion=cadena3.find(titular);
  cout<<"la posicion inicial del cambio es: " << posicion << endl;

  while(posicion != string::npos)
    {
      cadena3.replace(posicion, tamanio,suplente);
      posicion = cadena3.find( titular, posicion + 1 );
    }
  
  cout <<"despues del reemplazo:\n" << cadena3 << endl;
}
