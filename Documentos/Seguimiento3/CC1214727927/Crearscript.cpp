#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> // flujo de archivo
#include <cstdlib>
//tarea1 seguimiento 3 por julian andres montoya
//c.c 1214727927
using namespace std;

int main()
{
  ofstream datos( "datos.dat", ios::out );
      
  if ( !datos ) 
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }

  cout << "Escriba el Nombre, Numero de seguro social, Tarifa por hora y Horas Trabajadas" << endl
       << "Escriba fin de archivo para terminar la entrada.\n? ";

  int HorasTrabajadas;
  char nombre[ 30 ];
  double NumerosegSocial;
  float TarifaporHora;

  // lee los nombres, NumerosegSocial, TarifaporHora y HorasTrabajas de cin, y después los coloca en el archivo
  while ( cin >> nombre >> NumerosegSocial >> TarifaporHora >> HorasTrabajadas )
    {
      datos << nombre << ' ' << NumerosegSocial << ' ' << TarifaporHora << ' ' << HorasTrabajadas << endl;
      cout << "? ";
    }
  return 0;
}
