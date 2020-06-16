#include<string>

using std::string;



//Declaracion de la clase

class Complejo
{
public:
  Complejo(double =0,double =0); // constructor de la clase
  void asignarDatos(double,double); // prototipos de la diferentes funciones
  double obtenerParteReal();
  double obtenerParteImaginaria();
  void SumaNumerosComplejos(double,double,double,double);
  void RestaNumerosComplejos(double,double,double,double);
  void ImpresioNumeroComplejos();
  
private:
  double parteImaginaria; //miembros de datos
  double parteReal;
  
};
