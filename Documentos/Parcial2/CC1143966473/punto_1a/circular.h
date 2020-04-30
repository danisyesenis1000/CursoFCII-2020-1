#include <iostream> //importamos librerias necesarias
#include <iomanip>

using namespace std;

class Circulo // clase Circulo
{
 private:
  float radio; // radio
  float frecuencia_angular; // fracuencia angular
  float delta_t; // delta de tiempo
  float tiempo; // tiempo
  float n_it; // numero de iteraciones
  float fase; // fase
   
 public:
  Circulo(float =0,float =0, float  =0, float =0,float =0); // prototipo de la funcion cirulo
  void xpos(); // calcula la posicion en x
  void ypos(); // calcula la posicion en y
  ~Circulo(); // destructor de Circulo
};
