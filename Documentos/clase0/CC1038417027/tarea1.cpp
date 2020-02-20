#include <iostream>
#include <iomanip>

using namespace std;

int main(){

  //Para verificar los datos 
  int A1,L1; //Datos del largo y del ancho 
  float PP1; //Datos de la profundidad 
  float P1,V1,ASS1; //Datos de operaciones
  L1=25;//pies
  A1=15; //pies
  PP1=5.5; //pies
  


  int AL=A1+L1; //suma del largo y del ancho
  int ALM=A1*L1; //Multiplicacion del largo y del ancho

  
  
  P1=2*AL;
  V1=ALM*PP1;
  ASS1=2*AL*PP1 + ALM;
  //cout<<"El perimetro es:"<<P1<<endl;
  // cout<<"El Volumen es:"<<V1<<endl;
  // cout<<"el subterraneo es:"<<ASS1<<endl;
  //----------------------------------------------------


  int L[8]={25,25,25,25,30,30,30,30}; //Valores de largo 
  int A[8]={10,10,10,10,12,12,12,12}; //Valores de ancho
  float PP[8]={5.0,5.5,6.0,6.5,5.0,5.5,6.0,6.5}; //Valores de profundidad promedio
  int P[8]; //Perimetro 
  float V[8], ASS[8]; // Volumen y area de superficie subterranea 
  for(int i=0;i<=8;i++){
    int AL[8],ALM[8]; //definicion de las sumas y multiplicaciones 
    AL[i]=L[i]+A[i]; //largo mas ancho 
    ALM[i]=L[i]*A[i]; //largo por ancho 

    
    
    P[i]=2*AL[i]; //calcula el perimetro 
    V[i]=ALM[i]*PP[i]; //calcula el volumen 
    ASS[i]=2*AL[i]*PP[i] + ALM[i]; //Calcula el area de superficie subterranea
    
    //cout<<"El perimetro es:"<<P[i]<<"\n"
    //<<"El Volumen es:"<<V[i]<<"\n"
    //	<<"La produnfidad es:"<<ASS[i]<<endl;
    
    

  }

  cout<<setw(10)<<"Largo"<<setw(10)<<"Ancho"<<setw(10)<<"Profundidad"<<setw(10)<<"Perímetro"<<setw(10)<<"Volumen"<<setw(10)<<"Área"<<endl;

  cout<<setw(5)<<L[1]<<setw(2)<<"|"<<setw(5)<<A[1]<<setw(5)<<"|"<<setw(11)<<PP[1]<<setw(2)<<"|"<<setw(2)<<P[1]<<setw(2)<<"|"<<setw(2)<<V[1]<<setw(2)<<"|"<<setw(2)<<ASS[1]<<endl;
  

  
  return 0;
}
