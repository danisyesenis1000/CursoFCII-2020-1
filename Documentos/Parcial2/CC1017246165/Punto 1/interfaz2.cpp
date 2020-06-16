#include"clases2.h"

using namespace std;

Espiral::Espiral(double radio1,double fangular1,double tinter1,double ttotal1, int ntiempos1,double fase1,double posin1,double velin1) : Circular(radio1,fangular1,tinter1,ttotal1,ntiempos1,fase1){
  
  posin = posin1;
  velin = velin1;
  tinterch= tinter1;
  ttotalch=ttotal1;
  ntiemposch=ntiempos1;
}

Espiral::~Espiral(){
}

void Espiral::Datosxyz(){
  Datosxy();
  cout<<"La posición inicial en el eje z es: "<<posin<<endl;
  cout<<"la velocidad inicial en el eje z es: "<<velin<<endl;
}

double Espiral::zpos1(){
  xpos1(); //Hereda de la clase madre en la implementación
  ypos1();
  double zpl[ntiemposch]; 
  for(int i=0;i<=ntiemposch;i++){
    zpl[i]=posin+velin*tinterch*i;
    cout<<"La posicion en z para el tiempo t="<<i*tinterch<< "s es: "<<zpl[i] <<endl;
  }
}

double Espiral::zpos2(){
  double zpl;
  zpl=posin+velin*tinterch;
  return zpl;
}


double listaz(double R,double FA,double IT,double TT,int NT,double F,double P,double V){
  for(int i=0;i<=NT;i++){
    double ITL=i*IT;
    Espiral espira(R,FA,ITL,TT,NT,F,P,V);
    cout<<"La posición en z para el tiempo t="<<ITL<< "s es: " <<espira.zpos2() <<endl;
  }
}


void Espiral::listas(double R,double FA,double IT,double TT,int NT,double F,double P,double V){
  for(int i=0;i<=NT;i++){
    double ITL=i*IT;
    Espiral espira(R,FA,ITL,TT,NT,F,P,V);
    cout<<"La posición en x para el tiempo t="<<ITL<< "s es: " <<espira.xpos2() <<endl; 
    cout<<"La posición en y para el tiempo t="<<ITL<< "s es: " <<espira.ypos2() <<endl;
    cout<<"La posición en z para el tiempo t="<<ITL<< "s es: " <<espira.zpos2() <<endl;
  } 
}
