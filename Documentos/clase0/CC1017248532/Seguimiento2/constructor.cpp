#include "prototype.h"

Rectangulo::Rectangulo( double ancho, double largo){
  AsignarDatos( ancho, largo );
}

void Rectangulo::AsignarAncho( double ancho ){

  if (ancho <= 0.){
    
    cout << "Ingrese un valor válido para el ancho." << endl;
  }
  
  else{
    Ancho = static_cast <double> (ancho);
  }
}

void Rectangulo::AsignarLargo( double largo ){
  if (largo <= 0.){
    cout << "Ingrese un valor válido para el largo." << endl;
  }

  else{
    Largo = static_cast <double> (largo);
  }
}

double Rectangulo::ObtenerAncho(){
  return Ancho;
}

double Rectangulo::ObtenerLargo(){
  return Largo;
}
double Rectangulo::CalcularArea(){
  Area = Ancho*Largo;

  return Area;
}

double Rectangulo::CalcularPerimetro(){
  Perimetro = static_cast <double> (2)*(ObtenerAncho() + ObtenerLargo());

  return Perimetro;
}

void Rectangulo::AsignarDatos( double ancho, double largo ){
  AsignarAncho( ancho );
  AsignarLargo( largo );
  CalcularArea();
  CalcularPerimetro();
}

void Rectangulo::MostrarDatos(){
  cout << setw(7) << setiosflags(ios::left | ios::showpoint) << fixed << setprecision(1)<< "Largo | "
       << setw(9) <<   "Ancho | " << setw(13) <<  "Perímetro | " << setw(5) << "Área" << endl

       << setw(5) << setiosflags(ios::right) <<  Largo <<  setw(8) << Ancho << setw(13)
       << Perimetro << setw(7) << Area << endl;
}


