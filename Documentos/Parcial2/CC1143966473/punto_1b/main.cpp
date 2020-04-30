#include<iostream> // Incluimos la librerias necesarias 
#include<string>
#include<cmath>
#include "Espiral.h"

const float PI=3.1415; // definimos la variable PI
using namespace std;



int main() // inicializamos la funcion main
{
  float r=1.0; //radio
  float w=3.0; //frecuencia
  float t=2.0; //tiempo total
  float alpha=PI/2; //fase
  float dt=0.2; //intervalo de tiempo
  float z0=2.0; // Z inicial
  float vz=1.0; // velocidad en Z
    

  Espiral E(r,w,t,alpha,dt,z0,vz); // creo el objeto E de la clase Espiral
  E.xpos(); //se llama la funcion xpos
  E.ypos(); //se llama la funcion ypos
  E.zpos(); // se llama la funcion zpos
  return 0;
}// finaliza la funcion main
