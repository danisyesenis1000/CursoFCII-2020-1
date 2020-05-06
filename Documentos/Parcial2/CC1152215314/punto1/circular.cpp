#include "circular.h"

Circular::Circular(double t_ini,double t_end, double num_puntos,double r, double omega, double fase)
{
  //Defino las variables privadas para esta clase
  Definir_ti(t_ini);
  Definir_tf(t_end);
  Definir_n_puntos(num_puntos);
  Definir_R(r);
  Definir_w(omega);
  Definir_alpha(fase);
}

void Circular::Definir_ti(double t_ini)
{
  ti=t_ini;
}

void Circular::Definir_tf(double t_end)
{
  tf=t_end;
}

void Circular::Definir_n_puntos(double num_puntos)
{
  n_puntos=num_puntos;
}

void Circular::Definir_R(double r)
{
  R=r;
}

void Circular::Definir_w(double omega)
{
  w=omega;
}

void Circular::Definir_alpha(double fase)
{
  alpha=fase;
}

double Circular::Paso()
{
  double Dt=(tf-ti)/n_puntos;
  return Dt;
}

//Calcula la trayectoria en x(t) usa los parametros que quiere el usuario
void Circular::Trayectoria_X(vector< double >&x)
{
  double t=ti;
  dt=Paso();
  for(int i=0;i<n_puntos;i++)
    {
      x.push_back(R*cos(w*t+alpha));
      t+=dt;
    }
}

//Calcula la trayectoria en y(t) usa los parametros que quiere el usuario
void Circular::Trayectoria_Y(vector< double >&y)
{
  double t=ti;
  dt=Paso();
  for(int i=0;i<n_puntos;i++)
    {
      y.push_back(R*sin(w*t+alpha));
      t+=dt;
    }
}

//Imprime en un archivo la trayectoria
void Circular::Imprimir(string nombre,vector< double >&x,vector< double >&y)
{
  fstream archivo_sal(nombre.c_str(),ios::out); //objeto para escribir en el archivo
  if(archivo_sal.fail())
    {
      cout << "Error al intentar abrir el archivo" << endl;
      exit(1);
    }
  for(int i=0;i<n_puntos;i++)
    {
      archivo_sal << left << fixed << setprecision(2) << setw(6) << x[i] << "   " << setw(6) << y[i] << endl;
    }
  archivo_sal.close();
}

//Destructor
Circular::~Circular()
{
  cerr << "ti: " << ti << " tf: " << tf << " n_puntos: " << n_puntos << " dt: " << dt << " R: "<< R << " w: " << w << " alpha: " << alpha << " Destructor clase Circular " << endl;
}
