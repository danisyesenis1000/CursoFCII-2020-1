/* Solo es necesario correr este código! */

#include "crear_archivo.h"


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
