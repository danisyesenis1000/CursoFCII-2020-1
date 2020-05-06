#include"clases1.h"

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
  void Datosxyz();
  double zpos1();
  double zpos2();
  void listas(double,double,double,double,int,double,double,double);
};
