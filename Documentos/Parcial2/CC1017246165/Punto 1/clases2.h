/*Se crearon dos formas de de clases, donde se crea la lista desde la clase y donde se crea una función que genera la lista a partir de la clase, ambas arrojan
El mismo resultado y se hizo con el fin de examinar su utilidad, más allá de cual fuera la más acertada o si había una más acertada que otra para los fines
del ejercicio
 */

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

class Espiral : public Circular{
private:
  double tinterch;
  double ttotalch;
  int ntiemposch; //Se podría definir esto público en un inicio y así heredarlo también, pero el ejercicio solo pide heredar el movimiento como tal y no sus datos, también se puede declarar protected y así manipularla desde la clase estos datos que se usan compartidamente, pero nada me indico que esto se pretendía en el ejercicio más allá de mostrar que la clase espiral hereda el movimiento circular como tal y lo puede expresar a través de ella. 
  double posin;
  double velin;
public:
  Espiral(double,double,double,double,int,double,double,double);
  ~Espiral();
  void Datosz();
  double zpos1();
  double zpos2();
};
