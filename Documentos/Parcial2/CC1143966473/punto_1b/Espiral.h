#include <iostream> //importamos librerias necesarias
#include <iomanip>

using namespace std;

class Circulo // clase Circulo
{
 protected:
  float radio; // radio
  float frecuencia_angular;  // fracuencia angular
  float delta_t; // delta de tiempo
  float tiempo; // tiempo
  float n_it;// numero de iteraciones
  float fase; // fase
  
 public:
  Circulo(float =0,float =0, float  =0, float =0,float =0); // prototipo de la funcion cirulo
  void xpos(); // calcula la posicion en x
  void ypos();// calcula la posicion en y
  ~Circulo(); // destructor de Circulo
  
};


class Espiral: public Circulo // clase espiral
{
 protected:
  float z0; // z inicial
  float vz; // velocidad en Z
 public:
  Espiral(float =0,float =0, float  =0, float =0,float =0,float =0,float=0);// prottipo de la funcion Espiral
  void zpos(); // funcion de la posicion en z
  ~Espiral(); // destructor de Espiral
  
};
