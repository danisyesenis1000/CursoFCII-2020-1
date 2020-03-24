#include <iostream>
#include <iomanip>

using namespace std;

int main(){

  //Para verificar los datos 
  //int A1,L1; //Datos del largo y del ancho 
  //float PP1; //Datos de la profundidad 
  //float P1,V1,ASS1; //Datos de operaciones
  //L1=25;//pies
  //A1=15; //pies
  //PP1=5.5; //pies
  


  //int AL1=A1+L1; //suma del largo y del ancho
  //int ALM1=A1*L1; //Multiplicacion del largo y del ancho

  
  
  //P1=2*AL1;
  //V1=ALM1*PP1;
  //ASS1=2*AL1*PP1 + ALM1;
  //cout<<"El perimetro es:"<<P1<<endl;
  // cout<<"El Volumen es:"<<V1<<endl;
  // cout<<"el subterraneo es:"<<ASS1<<endl;
  //----------------------------------------------------
  
  
  
  int L[8]={25,25,25,25,30,30,30,30}; //Valores de largo 
  int A[8]={10,10,10,10,12,12,12,12}; //Valores de ancho
  float PP[8]={5.0,5.5,6.0,6.5,5.0,5.5,6.0,6.5}; //Valores de profundidad promedio
  int Per[8]; //Perimetro 
  float V[8], ASS[8]; // Volumen y area de superficie subterranea 
  
  
  for(int i=0;i<=7;i++){
    int AL[8],ALM[8]; //definicion de las sumas y multiplicaciones 
    AL[i]=L[i]+A[i]; //largo mas ancho 
    ALM[i]=L[i]*A[i]; //largo por ancho 
    
    Per[i]=2*AL[i]; //calcula el perimetro
    V[i]=ALM[i]*PP[i]; //calcula el volumen 
    ASS[i]=2*AL[i]*PP[i] + ALM[i]; //Calcula el area de superficie subterranea
  
  }
  

  cout<<"largo"<<setw(10)<<"Ancho"<<setw(15)<<"Profundidad"<<setw(15)<<"Perimetro"<<setw(10)<<"Volumen"<<setw(10)<<"area"<<endl;
  cout<<"-----------------------------------------------------------------"<<endl;
  cout<<setw(5)<<L[0]<<setw(10)<<A[0]<<setw(15)<<PP[0]<<setw(15)<<Per[0]<<setw(10)<<V[0]<<setw(10)<<ASS[0]<<endl;
  cout<<setw(5)<<L[1]<<setw(10)<<A[1]<<setw(15)<<PP[1]<<setw(15)<<Per[1]<<setw(10)<<V[1]<<setw(10)<<ASS[1]<<endl;
  cout<<setw(5)<<L[2]<<setw(10)<<A[2]<<setw(15)<<PP[2]<<setw(15)<<Per[2]<<setw(10)<<V[2]<<setw(10)<<ASS[2]<<endl;
  cout<<setw(5)<<L[3]<<setw(10)<<A[3]<<setw(15)<<PP[3]<<setw(15)<<Per[3]<<setw(10)<<V[3]<<setw(10)<<ASS[3]<<endl;
  cout<<setw(5)<<L[4]<<setw(10)<<A[4]<<setw(15)<<PP[4]<<setw(15)<<Per[4]<<setw(10)<<V[4]<<setw(10)<<ASS[4]<<endl;
  cout<<setw(5)<<L[5]<<setw(10)<<A[5]<<setw(15)<<PP[5]<<setw(15)<<Per[5]<<setw(10)<<V[5]<<setw(10)<<ASS[5]<<endl;
  cout<<setw(5)<<L[6]<<setw(10)<<A[6]<<setw(15)<<PP[6]<<setw(15)<<Per[6]<<setw(10)<<V[6]<<setw(10)<<ASS[6]<<endl;
  cout<<setw(5)<<L[7]<<setw(10)<<A[7]<<setw(15)<<PP[7]<<setw(15)<<Per[7]<<setw(10)<<V[7]<<setw(10)<<ASS[7]<<endl;
  
  

  
  return 0;
}
