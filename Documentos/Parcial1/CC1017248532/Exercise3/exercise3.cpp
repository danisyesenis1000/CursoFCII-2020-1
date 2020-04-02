#include "exercise3.h"

Complejo::Complejo(double a, double b){
  
  AsignarDatos(a,b);
}

void Complejo::AsignarDatos(double a, double b){

  ParteReal = a;
  ParteImaginaria = b;
}

double Complejo::ObtenerParteReal(){
  
  return ParteReal;
}

double Complejo::ObtenerParteImaginaria(){

  return ParteImaginaria;
}

double Complejo::SumaComplejos(){
  
  double a2, b2; //Parameters of the complex to be added
  
  cout << "Ingrese los parámetros del numero complejo a usar como sumando. \n"
       << "Parte real: ";

  cin >> a2;

  cout <<"\nParte Imaginaria: ";

  cin >> b2;

  cout << "\n";

  Complejo Complejo2(a2,b2); //Creates the complex to be added

  cout << "El complejo sumando es: \n";
  Complejo2.ImprimirComplejo(); //Prints it!
  
  double as, bs; //Parameters of the resulting complex

  as = Complejo2.ObtenerParteReal() + ParteReal;
  bs = Complejo2.ObtenerParteImaginaria() + ParteImaginaria;

  Complejo ComplejoSuma(as,bs); //Creates the result complex

  cout << "El resultado de la suma es: \n";
  ComplejoSuma.ImprimirComplejo(); //Prints it!
}

double Complejo::RestaComplejos(){ //The comments for this function are a the same as the last function
  
  double a2, b2;
  
  cout << "Ingrese los parámetros del numero complejo a usar como sumando. \n"
       << "Parte real: ";

  cin >> a2;

  cout <<"\nParte Imaginaria: ";

  cin >> b2;

  cout << "\n";

  Complejo Complejo2(a2,b2);

  double ar, br;

  ar = ParteReal - Complejo2.ObtenerParteReal();
  br = ParteImaginaria - Complejo2.ObtenerParteImaginaria();

  Complejo ComplejoResta(ar,br);

  ComplejoResta.ImprimirComplejo();
}

void Complejo::ImprimirComplejo(){
  cout << ObtenerParteReal() << " + " << ObtenerParteImaginaria() << "i" << "\n" << endl; //Prints the complex in a + bi format
}
