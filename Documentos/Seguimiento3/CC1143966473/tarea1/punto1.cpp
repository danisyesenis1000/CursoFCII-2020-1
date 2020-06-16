#include <iostream>
#include <fstream> // flujo de archivo
#include <cstdlib>

using namespace std;


int main()
{
  cout<<"=====Escritura de archivos==========="<<endl;
  //Se crea el archivo de entrada
  ofstream archivoClientesSalida( "datos.dat", ios::out );
  
      
  if ( !archivoClientesSalida ) 
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }
  
  cout<<"Escriba en Nombre, Número de seguro social, Tarifa por hora, Horas trabajadas." << endl;
  cout<<"Escriba fin de archivo para terminar la entrada. "<<endl;
  cout<<"Ej: Alexis  555-77-4444   7.32  40" <<endl;
  cout<<"==================================\n?";

  
  char nombre[ 30 ];
  char numeroseguro[30];   
  float tarifahora;
  int horastrabajadas;

  //  Nombre, Número de seguro social, Tarifa por hora, Horas trabajadas de cin, y después los coloca en el archivo
  while ( cin >> nombre >> numeroseguro >> tarifahora >>horastrabajadas)
    {
      archivoClientesSalida << nombre << ' ' << numeroseguro << ' ' << tarifahora<< ' '<<horastrabajadas<< endl;
      cout << "? ";
    }
  
  return 0;
}
