#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

int main(){

  //Creacion y verificación de éxito en la creación del archivo
  string archivoseg = "nomina.dat";
  ofstream archivo_nomina;
  archivo_nomina.open(archivoseg.c_str());

  if (archivo_nomina.fail()){
    cout <<"El archivo no se abrió exitosamente"<<endl;
    exit(1);
  }

  //Formato de los datos
  archivo_nomina << setiosflags(ios::fixed)
		 << setiosflags(ios::showpoint)
		 << setprecision(2);

  
  //Datos que irán en el archivo

  archivo_nomina <<"B Caldwell "<<"555-88-2222 "<< 7.32 << setw(3) << 37 <<endl
		 <<"D Memcheck "<<"555-77-4444 "<< 8.32 << setw(3) << 40 <<endl
		 <<"R Potter   "<<"555-77-6666 "<< 6.54 << setw(3) << 40 <<endl
		 <<"W Rosen    "<<"555-99-8888 "<< 9.80 << setw(3) << 35 <<endl;
  
  //Cierre del archivo con los datos
  archivo_nomina.close();
  cout << "Archivo creado exitosamente"<<endl;
  return 0;
}
