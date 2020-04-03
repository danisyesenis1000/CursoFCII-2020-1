#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

  cout << "El texto guia sera numerical analysis, Richard L. Burden, 9th edition: "<< endl;  
  cout << "Los temas son: "<< endl;
  cout << " " << endl;
  
  cout << "Capitulo 11 "<< endl;
  cout << "1) El metodo del disparo lineal" << endl;
  cout << "2) El metodo del disparo para problemas no lineales" << endl;
  cout << "3) Metodo de diferecnias finitas para problemas lineales" << endl;
  cout << "4) Metodo de diferecnias finitas para problemas no lineales" << endl;
  cout << "5) El metodo de Rayleigh-Ritz" << endl;
  cout << " " << endl;
  cout << "Capitulo 12 "<< endl;
  cout << "6) Ecuaciones diferenciales parciales elipticas" << endl;
  cout << "7) Ecuaciones diferenciales parciales parabolicas" << endl;
  cout << "8) Ecuaciones diferenciales parciales hiperbolicas" << endl;
  cout << "9) Una introducion al metodo del elemento finito" << endl;  
  cout << " " << endl;

  srand( time( NULL ) );
  cout << " la suert nos dira que tema toca a cada grupo " << endl;
  for ( int tiro = 1; tiro <= 20; tiro++ ){
    cout << 1 + rand() % 9 << endl; 
  }
  
  
return 0; 
}
