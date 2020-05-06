#include<iostream> // incluir las funciones necesarias
#include<string>
#include<cmath>
#include "circular.h"

const float PI=3.1415; // definimos el parametro PI
using namespace std;



int main() // inicializamos la funcion main
{
  float r=1.0; //radio
  float w=3.0;// frecuancia angular
  float t=2.0; // tiempo total 
  float alpha=PI/2; // fase
  float dt=0.1; // delta de t

  Circulo c(r,w,t,alpha,dt); // objeto de la clase circular

  c.xpos(); // llamamos la funcion xpos
  c.ypos(); // llamamos la funcion ypos
  return 0;
} // finalizacion de la funcion main
