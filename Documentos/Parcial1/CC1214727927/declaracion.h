//Esta es la seccion de declarar la clase

class complejo
{

private: //miembros de datos

  double parteReal;
  double parteImaginaria;
   
public: //funciones miembro
  
  complejo(double =0,double =0);
  void asignarDatos(double, double);
  double obtenerParteReal();
  double obtenerParteImaginaria();
  void Suma(double,double,double,double);
  void Resta(double,double,double,double);
  void mostrarnumero();
};
