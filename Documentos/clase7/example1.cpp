#include <iostream>
#include <fstream> // flujo de archivo
#include <cstdlib>

using namespace std;


int main()
{
  ofstream archivoClientesSalida( "clientestest.dat", ios::out );
  
  // sale del programa si no puede crear el archivo
  //if ( archivoClientesSalida.fail() )      
  if ( !archivoClientesSalida ) 
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }

  cout << "Escriba la cuenta, nombre y saldo." << endl
       << "Escriba fin de archivo para terminar la entrada.\n? ";

  int cuenta;
  char nombre[ 30 ];
  double saldo;

  // lee la cuenta, nombre y saldo de cin, y después los coloca en el archivo
  while ( cin >> cuenta >> nombre >> saldo )
    {
      archivoClientesSalida << cuenta << ' ' << nombre << ' ' << saldo << endl;
      cout << "? ";
    }
  
return 0; 
} 
  
