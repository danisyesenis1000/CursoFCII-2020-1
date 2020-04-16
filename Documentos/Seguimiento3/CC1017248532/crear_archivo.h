#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

/* En el archivo creado se separará cada item con una ",", de forma que se pueda usar getline evitando el problema
que surge debido al espacio en el nombre de los usuarios */
void CrearArchivo(string nombre_archivo){

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
