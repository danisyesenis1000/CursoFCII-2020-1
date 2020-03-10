// LibroCalificar.h
#include <iostream>
#include <string>

using namespace std;

class LibroCalificar
{
 public:
  LibroCalificar( string ); 
  void establecerNombreCurso( string ); 
  string obtenerNombreCurso();
  void mostrarMensaje(); 
  void recibirCalificaciones();
  
  void mostrarReporteCalificaciones(); // muestra un reporte con base en las calificaciones
  
 private:
  string nombreCurso; // nombre del curso para este LibroCalificar
  int aCuenta; // cuenta de calificaciones A
  int bCuenta; 
  int cCuenta; 
  int dCuenta; 
  int fCuenta; 
}; 
