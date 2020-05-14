#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

/*
Notación:

LmW : Largo + Ancho
LpW : Largo * Ancho
 */

float perimetro(float lmw) {return 2*lmw;}

float volumen(float lpw, float d) {return lpw*d;}

float area_ss(float lmw, float lpw, float d){
  return 2*lmw*d + lpw;
}

int main(){

  float perim, vol, area;
  
  vector <float> l {25.,30.};
  vector <float> w {10.,12.};
  vector <float> d {5.,5.5,6.0,6.5};
  
  cout << setw(7) << setiosflags(ios::left | ios::showpoint) << fixed << setprecision(1)<< "Largo | " << setw(9) <<   "Ancho | " << setw(15) << "Profundidad | " << setw(13) <<  "Perímetro | " << setw(11) <<  "Volumen | " << setw(5) << "Área" << endl;

  for(int i = 0; i < 2; i++){
    for(int k = 0; k < 4; k++){

      float LmW = l[i] + w[i];
      float LpW = l[i]*w[i];

      perim = perimetro(LmW);
      vol = volumen(LpW,d[k]);
      area = area_ss(LmW,LpW,d[k]);
      
      cout << setw(6) << setiosflags(ios::left) <<  l[i] << "|  " <<  setw(5) << w[i] << "|  "  << setw(12) <<  d[k] << "|  "<< setw(10) << perim << "|  "<< setw(7)  <<  vol << "|  "<< setw(5) << area << endl;
    
    }
  }
   return 0;
}
