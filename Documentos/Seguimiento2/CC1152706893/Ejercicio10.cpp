//Ejercicio 10
//Luisa Fernanda Vargas Restrepo

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  string cadena;
  cout << "Ingrese el mensaje: " << endl;
  cin>>cadena;
  int posicion = cadena.find( "e" );
  while ( posicion != string::npos )
    {
      cadena.replace( posicion, 1, "x" );
      posicion = cadena.find( "e", posicion + 1 );
    }
  
  cout << "El mensaje cambiado es: " << cadena << endl;
    
  return 0;
}
