#include <vector>

class Circular
{
private:
  double radio,fase,frecAngular; //radio,fase,frecAngular
  double tinicial; //tiempo inicial 
  double tfinal; //tiempo final 
  double tTotal; //tiempo total 
  int n; //numero de particiones del intervalo
  

public:
  //orden de ingreso
  //radio,fase,frecuencia angular,tiempo inicial,tiempo final, tiempo total, numero de particiones
  Circular(double,double,double,double,double,double,int);
  void establecerDatos(double,double,double,double,double,double,int);
  double xpos(double);
  double ypos(double);
  
  void mostrarDatos();
  //para obtener los valores en z 
  double retornartinicial();
  double retornartfinal();
  double retornarttotal();
  int retornarintervalo();
  void resultado(double [],double []);
  //montar funciones por punteros, generaba fallos
  //void resultado(double [],double (*)(double));
  //double (*temp)(double);
  
};
  
