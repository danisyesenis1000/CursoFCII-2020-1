#include "espiral.h"

int main()
{
  vector<double> pos_x;
  vector<double> pos_y;
  vector<double> pos_z;

  //Objeto(tiempo_i,tiempo_f,numero_puntos,radio,vel_ang,fase,vel_z,z_0)
  Espiral particula(0.0,20.0,1000,7,10,2,12,0);
  particula.Trayectoria_X(pos_x);                  //Calcule trayectoria en X
  particula.Trayectoria_Y(pos_y);                  //Calcule trayectoria en y
  particula.Trayectoria_Z(pos_z);                  //Calcule trayectoria en z
  particula.Imprimir("salida_XY.txt","salida_Z.txt",pos_x,pos_y,pos_z);
  return 0;
}
