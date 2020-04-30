#include "espiral.h"

Espiral::Espiral(double t_ini,double t_end, double num_puntos,double r, double omega, double fase,double v_z,double z_0)
  : Circular(t_ini,t_end,num_puntos,r,omega,fase)  //hago uso del constructor de la clase Circular
{
  //Define las variables que son privadas en esta clase y que necesito
  Definir_ti(t_ini);
  Definir_n_puntos(num_puntos);
  Definir_v(v_z);
  Definir_z0(z_0);
}

void Espiral::Definir_ti(double t_ini)
{
  ti=t_ini;
}

void Espiral::Definir_n_puntos(double num_puntos)
{
  n_puntos=num_puntos;
}

void Espiral::Definir_v(double v_z)
{
  v=v_z;
}

void Espiral::Definir_z0(double z_0)
{
  z0=z_0;
}

void Espiral::Trayectoria_Z(vector< double >&z)
{
  double t=ti;
  dt=Circular::Paso();          // esta funcion es de la clase base Circular, como devuelve un valor la puedo aprovechar!
  for(int i=0;i<n_puntos;i++)   // evoluciono Z(t)
    {
      z.push_back(z0+v*t);
      t+=dt;
    }
}

void Espiral::Imprimir(string nombre1,string nombre2,vector< double >&x,vector< double >&y,vector< double >&z)
{
  Circular::Imprimir(nombre1,x,y);                      //Esta funcion es de la clase base Circular, imprimo
  fstream archivo_sal(nombre2.c_str(), ios_base::out);  //abro el archivo
  if(archivo_sal.fail())
    {
      cout << "Error al intentar abrir el archivo" << endl;
      exit(1);
    }
  for(int i=0;i<n_puntos;i++)
    {
      archivo_sal << left << fixed << setprecision(2) << setw(5) << z[i] << "  " <<endl;
    }
  archivo_sal.close();
}

//DESTRUCTOR
Espiral::~Espiral()
{
  cerr << "ti: " << ti << " dt: " << dt << " n_puntos: " << n_puntos << " v: " << v << " z0: " << z0 << "  Destructor clase Espiral" << endl;
}
