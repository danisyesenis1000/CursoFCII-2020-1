#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
class Rectangulo
{

public:
  Rectangulo(double, double );
  void asignarAncho(double);
  void asignarLargo(double);
  double obtenerAncho();
  double obtenerLargo();
  void mostrarDatos();
  double asignarDatos(double,double);
  double area(double, double);
  double perimetro(double, double);
  
  
private:
  double largo;
  double ancho;

};

Rectangulo::Rectangulo(double largo ,double ancho)
{
  asignarAncho(ancho);
  asignarLargo(largo);
  asignarDatos(largo,ancho);
}
void Rectangulo::asignarAncho(double a)
{
  ancho = a;
}

void Rectangulo::asignarLargo(double l)
{
  largo = l;
}
double Rectangulo::obtenerAncho()
{
  return ancho ;
}
double Rectangulo::obtenerLargo()
{
  return largo ; 
}
double Rectangulo::area(double l, double a)
{
  double are;
  are = l * a;
  return are;
}
double Rectangulo::asignarDatos(double l, double a)
{
  double perimet,are;
  are = Rectangulo::area(l,a);
  perimet =Rectangulo::perimetro(l,a);
  return perimet,are;
}
double Rectangulo::perimetro(double l, double a)
{
  double p;
  p =2*l + 2*a;
  return p;
}
void Rectangulo::mostrarDatos()
{
  cout<<setw(5)<<largo<<setw(10)<<ancho<<setw(15)<<perimetro(largo,ancho)<<setw(10)<<area(largo,ancho)<<endl;
  // cout<<primet;
  return ; 
}
int main()
{

  cout<<"Largo"<<setw(10)<<"Ancho"<<setw(15)<<"Perimetro"<<setw(10)<<"Area"<<endl;

  Rectangulo b(10,14);
  Rectangulo a(2,4);
  Rectangulo c(2,3);
  Rectangulo d(10,2);
  

  a.mostrarDatos();
  b.mostrarDatos();
  c.mostrarDatos();
  d.mostrarDatos();
  
  return 0;
}
