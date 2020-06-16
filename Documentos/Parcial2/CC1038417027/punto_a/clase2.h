#include "clase1.h"


class Expiral : public Circular
{
 private:
  double velz,zInicial;

 public:
  Expiral(double,double,double,double,double,double,int,double,double);//Hereda los datos de Circular y añade velocidad en z y posicion inicial de z
  double zpos(double);
  void establecerDatos(double,double);
  void resultado2(double []);
  
};

