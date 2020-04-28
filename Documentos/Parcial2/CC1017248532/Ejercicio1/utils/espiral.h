#ifndef ESPIRAL_H
#define ESPIRAL_H

#include "circular.h"

class Espiral : public Circular {

 public:
  Espiral(double, double, double, int, double, double , double );
  ~Espiral();
  
  double zpos(double );
  void PrintTimeEvolution(void);
  
 private:
  double Vz;
  double Z0;
  
};

#endif
