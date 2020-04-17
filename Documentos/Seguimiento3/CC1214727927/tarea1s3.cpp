#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> // flujo de archivo
#include <cstdlib>
//tarea1 seguimiento 3 por julian andres montoya
//c.c 1214727927
using namespace std;


void imprimirLinea(const string nombre, float TarifaporHora, int HorasTrabajadas,float sueldo);

void funcionarchivo(ifstream *datos);

int main()
{
  ifstream datos("datos.dat");
  
  funcionarchivo(&datos);
  return 0;
}


void imprimirLinea(const string nombre, float TarifaporHora, int HorasTrabajadas,float sueldo)
{
  cout << left << setw( 10 ) << nombre << setw(25)  << TarifaporHora << setw(12)  << HorasTrabajadas << setw(5) << sueldo <<endl;
}

void funcionarchivo(ifstream *datos)
{
  if ( !datos ) 
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }
  char nombre[ 30 ];
  float TarifaporHora;
  int HorasTrabajadas;
  double NumerosegSocial;
  float sueldo;

  
  cout << left << setw( 10 ) << "Nombre" << left <<  setw( 13 ) <<  "Tarifa por hora" << setw( 13 ) << "    Horas Trabajadas" << setw ( 10 ) << "    Sueldo" << endl << fixed << showpoint;
  while ( *datos >> nombre >> NumerosegSocial >> TarifaporHora >> HorasTrabajadas )
    {
      sueldo=TarifaporHora*HorasTrabajadas;

      imprimirLinea( nombre, TarifaporHora , HorasTrabajadas, sueldo );
      }
 
}
