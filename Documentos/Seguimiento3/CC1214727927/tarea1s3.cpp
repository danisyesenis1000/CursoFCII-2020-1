#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> // flujo de archivo
#include <cstdlib>
//tarea1 seguimiento 1 por julian andres montoya
//c.c 1214727927
using namespace std;

void imprimirLinea( const string nombre, float &TarifaporHora, int &HorasTrabajadas); // prototipo

int main()
{

  ifstream datos( "datos.dat" );

  //if ( !archivoClientesEntrada )
  if ( datos.fail() )   
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }

  int HorasTrabajadas;
  char nombre[ 30 ];
  double NumerosegSocial;
  float TarifaporHora;
  float sueldo;
  
  cout << left << setw( 10 ) << "Nombre" << left <<  setw( 13 ) <<  "Tarifa por hora" << setw( 13 ) << "    Horas Trabajadas" << setw ( 10 ) << "    Sueldo" << endl << fixed << showpoint;

  // muestra cada registro en el archivo
  while ( datos >> nombre >> NumerosegSocial >> TarifaporHora >> HorasTrabajadas )
    imprimirLinea( nombre, TarifaporHora , HorasTrabajadas );
  
  return 0;
}

// muestra una sola linea del archivo
void imprimirLinea( const string nombre, float &TarifaporHora, int &HorasTrabajadas)
{
  float sueldo=TarifaporHora*HorasTrabajadas;
  cout << left << setw( 10 ) << nombre << setw(25)  << TarifaporHora << setw(12)  << HorasTrabajadas << setw(5) << sueldo <<endl;
  //<< setw( 7 ) << setprecision( 2 ) << right << saldo << endl;
}
