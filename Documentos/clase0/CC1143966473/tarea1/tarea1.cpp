#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
  float largo;//Se define la variable largo como un float
  float ancho;//Se define la variable  ancho como un float
  float profundidad_promedio; //Se define la variable profundidad_promedio como un float

  float slya,mlya,perimetro,volumen, area_superficie; // se definen las diferentes variables a calcular

  mlya=largo*ancho; //se cacula el largo por el ancho
  slya=largo+ancho; // se calcula la suma del largo y el ancho
  
  perimetro=2*(slya); // se calcula el perimeto
  volumen=mlya*profundidad_promedio; //se calcula el volumen
  area_superficie=2*slya*profundidad_promedio+mlya; //se calcula el area de superficie


  // Se da inicio a la tabla
  cout<<"\nLargo"<<" | "
      <<"Ancho"<<" | "
      <<"Profundidad"<<" | "
      <<"Perímetro"<<" | "
      <<"Volumen"<<" | "
      <<"Área superficie subterranea"<<" | "
      <<endl;

  // se llena la tabla
  for(float p=5.0;p<=6.5;p=p+0.5){
    profundidad_promedio=p;
    largo=25;
    ancho=10;
    mlya=largo*ancho;
    slya=largo+ancho;
  
    perimetro=2*(slya);
    volumen=mlya*profundidad_promedio;
    area_superficie=2*slya*profundidad_promedio+mlya;
    cout<<setw(4)<<largo<<"  | "<<setw(4)<<ancho<<"  |"<<setw(6)<<profundidad_promedio<<"\t    |\t"<<setw(3)<<perimetro<<"\t|"<<setw(6)<<volumen<<"\t  |"<<setw(16)<<area_superficie<<"\t\t|"<<endl;
    
   }
   for(float p=5;p<=6.5;p=p+0.5){
    profundidad_promedio=p;
    largo=30;
    ancho=12;
    mlya=largo*ancho;
    slya=largo+ancho;
  
    perimetro=2*(slya);
    volumen=mlya*profundidad_promedio;
    area_superficie=2*slya*profundidad_promedio+mlya;
    cout<<setw(4)<<largo<<"  | "<<setw(4)<<ancho<<"  |"<<setw(6)<<profundidad_promedio<<"\t    |\t"<<setw(3)<<perimetro<<"\t|"<<setw(6)<<volumen<<"\t  |"<<setw(16)<<area_superficie<<"\t\t|"<<endl;
    
  }

  
  cout<<"\n"<<endl;

  return 0;

}
