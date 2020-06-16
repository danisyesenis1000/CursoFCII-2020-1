#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

class Circular
{
 public:
  Circular(double , double ,double ,double ,double ,double ); //Constructor con dos valores predeterminados t_ini, t_end, n_puntos, radio, omega=0, alpha=0
  ~Circular();                               //Destructor de la clase
  void Xpos(double );                        //funcion calcula x en el tiempo t
  void Ypos(double );                        //funcion calcula y en el tiempo t
  double Paso(void );                        //funcion que calcula el dt con los parametros elegidos por el usuario
  void Trayectoria_X(vector< double >&);     //funcion que calcula x(t)
  void Trayectoria_Y(vector< double >&);     //funcion que calcula y(t)
  void Imprimir(string,vector< double >&,vector< double >&);  //funcion que imprime en archivos los valores de la trayectoria

  //Funciones para definir los valores privados de esta clase
  void Definir_ti(double);
  void Definir_tf(double);
  void Definir_n_puntos(double);
  void Definir_R(double);
  void Definir_w(double);
  void Definir_alpha(double);

 private:
  double ti;            // tiempo inicial
  double tf;            // tiempo final
  double n_puntos;      // numero de puntos que quiere el usuario en la trayectoria
  double dt;            // Delta(t)
  double R;             // radio de la trayectoria circular
  double w;             //velocidad angular de la particula
  double alpha;         //fase
  vector<double> x;     //vector donde agregaran cada paso de tiempo la posicion x
  vector<double> y;     //vector donde agregaran cada paso de tiempo la posicion y
};

//Me decidi por trabajar con vectores ya que cuando los defino no debo ponerle longitud, ya que la cantidad de puntos en la trayectoria los decide el usuario cuando crea el objeto. 
