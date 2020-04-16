/* Solo es necesario correr este código! */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void CrearArchivo(string);
void CalcularIngresoBruto(ifstream *, string);
void ImprimirLinea(string, string, float, int);

int main(){

  string Nombre_Archivo;

  Nombre_Archivo = "lista.dat";
  
  CrearArchivo(Nombre_Archivo);
  ifstream archivo_ent; //Creando el objeto de archivo de entrada 
  ifstream *archivo_entPTR = &archivo_ent; //Creando el puntero para pasar a la función

  CalcularIngresoBruto(archivo_entPTR, Nombre_Archivo);
  
  cout << endl;
  return 0;
}

void CalcularIngresoBruto(ifstream *archivoPTR, string nombre_archivo){


  archivoPTR->open(nombre_archivo); //Llama la función open del objeto que referencia archivoPTR

  string linea;
  
  string Nombre;
  string SeguroSocial;
  float TarifaHora;
  int HorasTrabajadas;
  
  int counter = 0;
  
  while (getline(*archivoPTR, linea, ',')){

    switch(counter){
     
    case 0:
      Nombre = linea;
      counter++;
      break;

    case 1:
      SeguroSocial = linea;
      counter++;
      break;

    case 2:
      TarifaHora = stof(linea);
      counter++;
      break;

    case 3:
      HorasTrabajadas = stoi(linea);
      counter = 0;
      ImprimirLinea(Nombre, SeguroSocial, TarifaHora, HorasTrabajadas);
      break;
    }
  }
}

void ImprimirLinea(string nombre, string seguro, float tarifa, int horas)
{
  cout << setiosflags(ios::left | ios::showpoint) << setprecision(2) << fixed
       << setw(12) << nombre
       << setw(14) << seguro
       << setw(5) << tarifa*horas;
}

void CrearArchivo(string nombre_archivo){
/* En el archivo creado se separará cada item con una ",", de forma que se pueda usar getline evitando el problema
que surge debido al espacio en el nombre de los usuarios */
  
  ofstream archivo_sal;

  archivo_sal.open(nombre_archivo);
  archivo_sal << endl;
  
  vector <string> Nombres{ "B Caldwell", "D Memcheck", "R Potter", "W Rosen" };
  vector <string> SeguroSocial{ "555-88-2222", "555-77-4444", "555-77-6666", "555-99-8888"};
  vector <float> TarifaHora{ 7.32, 8.32, 6.54, 9.80 };
  vector <int> HorasTrabajadas{ 37, 40, 40,35 };
  
  for (int i = 0; i < Nombres.size(); i++){
   
    archivo_sal << setiosflags(ios::right | ios::showpoint ) << setprecision(3) //Poniendo las flags deseadas y la precision
		<< setw(10) << Nombres[i] << ","
		<< setw(12) << SeguroSocial[i] << ","
		<< setw(5) << TarifaHora[i] << ","
		<< setw(3) << HorasTrabajadas[i] << ","
		<< endl;
  }
  
}
