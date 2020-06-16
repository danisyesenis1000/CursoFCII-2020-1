#include "clases2.h"

int main(){
  int elect;
  double r1,fa1,it1,tt1,nt1,f1,p1,v1;
  r1=4;
  fa1=1.3;
  it1=1;
  tt1=6;
  nt1=tt1/it1; //Calcula la cantidad de intervalos
  f1=0.78;
  p1=0.5;
  v1=2.2;
  double r2,fa2,it2,tt2,nt2,f2,p2,v2;
  cout <<"Si desea usar los datos suministrados por el programa digite el numero '1', si los desea ingresar manualmente digite cualquier otro número natural"<<endl;
  cin >>elect;
  if(elect==1){ //Se usa de acuerdo a los datos dados por el programa
    //Circular circulo1(r1,fa1,it1,tt1,nt1,f1); Muestra los datos que está usando el programa por defecto
    Espiral espira1(r1,fa1,it1,tt1,nt1,f1,p1,v1);
    espira1.Datosxyz();
    espira1.zpos1();
    espira1.listas(r1,fa1,it1,tt1,nt1,f1,p1,v1);
  }
  else{ //Se usa si el usuario desea ingresar los datos 
    cout <<"Ingrese el valor del radio"<<endl;
    cin>>r2;
    cout <<"Ingrese el valor de frecuencia angular"<<endl;
    cin>>fa2;
    cout <<"Ingrese el intervalo de tiempo"<<endl;
    cin>>it2;
    cout <<"Ingrese el tiempo total de movimiento"<<endl;
    cin>>tt2;
    nt2=tt2/it2; //Calcula la cantidad de intervalos
    cout <<"Asigne la fase correspondiente"<<endl;
    cin>>f2;
    cout <<"Ingrese la posición inicial: "<<endl;
    cin>>p2;
    cout <<"Ingrese la velocidad inicial: "<<endl;
    cin>>v2;
    Espiral espira2(r2,fa2,it2,tt2,nt2,f2,p2,v2);
    espira2.Datosxyz();
    espira2.zpos1();
    espira2.listas(r2,fa2,it2,tt2,nt2,f2,p2,v2);
  }
  
  return 0;
}
