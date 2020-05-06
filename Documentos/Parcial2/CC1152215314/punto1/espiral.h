#include "circular.h"

class Espiral: public Circular
{
 public:
  Espiral(double, double, double, double, double, double, double,double );
  ~Espiral();
  void Trayectoria_Z(vector<double>&);
  void Imprimir(string ,string , vector<double>&,vector<double>&,vector<double>&);

  void Definir_ti(double);
  void Definir_n_puntos(double);
  void Definir_v(double);
  void Definir_z0(double);
  
 private:
  double ti;
  double tf;
  double dt;
  double n_puntos;
  double v;
  double z0;
};
