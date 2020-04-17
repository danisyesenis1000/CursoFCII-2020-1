#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>


using namespace std;

void Nomina( char [][10], char [][20], float*, float*); //Función prototipo.

int main()
{
  ofstream archivoCreado("Lista.txt");   // Crea el archivo de texto con los datos.
  

  if ( archivoCreado.fail() )          // Se cerciora de que no haya un documento igual.
    {
      cout << "No se pudo abrir el archivo " << endl;
      exit( 1 );
    }
  
  char Nombres[4][10] = {"BCaldwell", "DMemcheck", "RPotter", "WRosen"};      // Arreglo con los nombres
  char Tarifas[4][20] = {"555-88-2222", "555-77-4444", "555-77-6666", "555-99-8888"};  // Arreglo con el número de seguridad social
  float Horas[] = {7.32, 8.32, 6.54, 9.80};   // Arreglo de la tarifa por horas.
  float Trabajadas[] = {37, 40,40,35};     // Arreglo de horas trabajadas.

  for(int i=0; i<4; i++)     // ciclo que corre sobre todo el arreglo para que haga la tabla en el archivo de texto.
    archivoCreado << Nombres[i] << ' ' << Tarifas[i]
		  << ' ' << Horas[i] << ' ' << Trabajadas[i] << endl;
  


  cout << left << setw( 10 ) << "Nombres" << setw( 13 )       // Es para la tabla que se va a desplegar en la pantalla
       << "Seguro social " << setw( 10 ) << " Nomina" << endl
       << fixed << showpoint;


  Nomina( Nombres, Tarifas, Horas, Trabajadas);    
  
  return 0;
  
}

/*

Función que lee el archivo de texto, multiplica la tarifa por hora * las horas trabajadas
para que de la nomina, luego con esta información muestra en pantalla, el nombre, 
el número de seguridad social y la nomina.

*/

void Nomina(char Nombres[][10], char Tarifas[][20], float * Horas, float * Trabajadas)  
{
  ifstream AbrirArchivo("Lista.txt");   // Para leer el archivo

  if (AbrirArchivo.fail())     // Verifica que el archivo existe
    {
      cout << "No se pudo abrir el archivo " << endl;
      exit( 1 );
    }

  float *Pago;

  for (int i = 0; i < 4; i++)      // Ciclo que saca la nomina y despliega en pantalla.
    {
      Pago[i] = Horas[i] * Trabajadas[i];
      cout << left << setw( 10 ) << Nombres[i] << setw( 13 )
	   << Tarifas[i] << setw( 10 ) << setprecision( 2 ) << right
	   << Pago << endl;
    }
  
}
