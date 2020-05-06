/*Se crearon dos formas de de clases, donde se crea la lista desde la clase y donde se crea una función que genera la lista a partir de la clase, ambas arrojan
El mismo resultado y se hizo con el fin de examinar su utilidad, más allá de cual fuera la más acertada o si había una más acertada que otra para los fines
del ejercicio
 */

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

//Clase circular y ecuaciones de movimiento

class Circular{
private:
  double radio; //Radio del circulo
  double fangular; //Frecuencia angular
  double tinter; //Intervalos de tiempo
  double ttotal; //Tiempo total
  int ntiempos; //Numero de intervalos
  double fase; //Fase angular
public:
  Circular(double,double,double,double,int,double); //Constructor
  ~Circular(); //Destructor
  void Datosxy();
  double xpos1(); //Funcion miembro eje x
  double ypos1(); //Funcion miembro eje y
  double xpos2(); //Función miembro eje x
  double ypos2(); //Función miembro eje y
};

