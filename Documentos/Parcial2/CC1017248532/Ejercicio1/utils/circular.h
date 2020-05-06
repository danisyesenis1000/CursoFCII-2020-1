#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <iostream>
#include <math.h>
#include <fstream>
#include <string>

using namespace std;

class Circular{

 public:
  Circular(        // constructor  
	   double, // radio del circulo
	   double, // frecuencia angular
	   double, // pequeño intervalo de tiempo
       double, // tiempo total
	   int, // numero de intervalos
	   double  // fase
	   ); 

  ~Circular(); //destructor

  double xpos(double); // Solo se le brinda el tiempo actual

  double ypos(double);
  
  void PrintTimeEvolution(void);

 protected:

  double R;
  double W;
  double dT;
  double T;
  int N;
  double Phi;
};

#endif



