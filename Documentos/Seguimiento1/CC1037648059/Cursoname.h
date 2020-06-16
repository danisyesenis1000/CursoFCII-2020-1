// LibroCalificar.h
// Definición de la clase LibroCalificar. Este archivo presenta
// interfaz publica sin revelar las implementaciones de los miembros de las
// funciones, que se definen en LibroCalificar.cpp

#include <string>
//using std::string;

// LibroCalificar class definition
class LibroCalificar
{
public:
   LibroCalificar(string); 
   void setCourseName(string); 
   string getCourseName(); 
   void displayMessage();
   void determinarPromedioClase();
   void asignarDatos();
   void asignarAncho();
   void asignarLargo();
   double  area();
   double  perimetro();
   void mostrarDatos();
   void obtenerAncho();
   void obtenerLargo();
   
private:
   string courseName;
   double largo;
   double ancho;
};  
