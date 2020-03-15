#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){

  // Defino las variables que se van a utilizar en la tabla.                                                                                   

  int l, a, la, la1;
  float p, per, v, as;

  // Imprime las lineas del título.                                                                                                            

  cout << "Largo    Ancho    Profundidad    Perímetro    Volumen    Área subterranea\n";
  cout << "-----    -----    -----------    ---------    -------    ----------------\n";


  // 1                                                                                                                                         

  for (float p = 5.0; p<=6.5 ; p += 0.5){
    l = 25;
    a = 10;
    la = l*a;
    la1 = l+a;
    per = 2*la1;
    v = la*p;
    as = 2*la1*p+la;

    cout << setw(4) << setiosflags(ios::showpoint) << l
         << setw(8) << a << setw(15) << p << setw(14) << per
         << setw(12) << v << setw(12) << as << endl;

  }

  // 2                                                                                                                                         

  for (float p = 5.0; p<=6.5 ; p += 0.5){
    l = 30;
    a = 12;
    la = l*a;
    la1 = l+a;
    per = 2*la1;
    v = la*p;
    as = 2*la1*p+la;

    cout << setw(4) << setiosflags(ios::showpoint) << l
         << setw(8) << a << setw(15) << p << setw(14) << per
         << setw(12) << v << setw(12) << as << endl;
  }
  return 0;
}

