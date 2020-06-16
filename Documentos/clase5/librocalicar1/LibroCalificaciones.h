#include <string>

//using namespace std;
using std::string;

class LibroCalificaciones
{
public:
  // constante -- número de estudiantes que tomaron la prueba.  Observe los datos públicos
  const static int estudiantes = 10; //TODOS los objetos comparten una copia de los miembros de datos static de la clase.

  LibroCalificaciones( string, const int [] );
  void establecerNombreCurso( string );
  string obtenerNombreCurso(); 
  void mostrarMensaje();
  
  void procesarCalificaciones(); // realiza varias operaciones con los datos de calificaciones
  int obtenerMinimo(); // 
  int obtenerMaximo(); //
  double obtenerPromedio(); 
  void imprimirGraficoBarras(); 
  void imprimirCalificaciones(); 
 private:
  string nombreCurso; 
  int calificaciones[ estudiantes ]; // arreglo de calificaciones de estudiantes
};
