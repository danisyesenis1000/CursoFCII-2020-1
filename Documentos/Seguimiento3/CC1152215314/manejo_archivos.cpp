#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>

#define SIZE 4  //numero de personas en la tabla de datos

using namespace std;

void crear_archivo(string);
void calculo_archivo(fstream&);

int main()
{
  string nombre_archivo = "datos.txt";   //nombre que tendra el archivo

  crear_archivo(nombre_archivo);         //creo el archivo con sus datos

  fstream archivo_ent(nombre_archivo.c_str(),ios::in);  //objeto para leer el archivo que se creo
  if(archivo_ent.fail())
    {
      cout << "Error al intentar abrir el archivo" << endl;
      exit(1);
    }
  
  calculo_archivo(archivo_ent);          //calculo los pagos pasando el archivo a la funcion calculo_archivo
  archivo_ent.close();                   //cierro el archivo
  return 0;
}


void crear_archivo(string nombre)
{
  fstream archivo(nombre.c_str(),ios::out);
  if(archivo.fail())
    {
      cout << "Fallo abrir el archivo" << endl;
      exit(1);
    }

  string Nombres[SIZE]={"B Caldwell","D Memcheck","R Potter","W Rosen"};
  string Numero[SIZE]={"555-88-2222","555-77-4444","555-77-6666","555-99-8888"};
  double Tarifa[SIZE]={7.32,8.32,6.54,9.80};
  int Horas[SIZE]={37,40,40,35};
  for(int i=0;i<SIZE;i++)
    {
      archivo << left << setw(11) << *(Nombres+i) << setw(12) << *(Numero+i) << setw(5) << fixed << setprecision(2) << *(Tarifa+i) << setw(2) << *(Horas+i) << endl;
    }

  archivo.close(); //cerrar el archivo
}

void calculo_archivo(fstream& archivo)
{
  string nombre1,nombre2,numero1,numero2,numero3;
  double tarifa,hora,pago;
  cout << left <<setw(11) << "Nombre" << setw(16) << "Seguro social" << setw(7) << fixed << setprecision(2) << "Pago" << endl;
  cout << endl;
  for(int i=0;i<SIZE;i++)
    {
      archivo >> nombre1 >> nombre2 >> numero1 >> tarifa >> hora;
      pago=tarifa*hora;
      cout << left << setw(11) << nombre1+" "+nombre2 << setw(16) << numero1 << setw(7) << pago << endl;;
    }
}
