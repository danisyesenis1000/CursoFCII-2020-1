#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

class Circular
{
private:
  double radio; 
  double omega; //frecuencia angular
  double alpha; //Fase angular
public:
  Circular(double,double,double,int,double); //constructor
  ~Circular(); //destructor
  double dt; //pequeño intervalo de tiempo
  int n_intervalos; //Numero de intervalos
  void datos();
  double xpos();
  double ypos();
};

class Espiral: public Circular //clase hija que hereda los atributos de Circular
{
private:
    //aparte de lo heredado de Circular, tiene posicion inicial en z y velocidad inicial en z
    double z0;
    double vz0;
public:
    Espiral(double,double,double,int,double, double, double); 
    ~Espiral();
    void datosz();
    double zpos();
};
