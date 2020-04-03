//Seguimiento de secuencia de Fibonacci por vectores y por listas

//Librerias
#include<iostream>
#include<string.h>
#include<iomanip>
#include<vector>

using namespace std;

int listafibo(int nf1){
  int fnl[nf1];
  for(int i=0;i<nf1;i++){
    if (i==0){
      fnl[i]=0;
    }
    if (i==1){
      fnl[i]=1;
    }
    if (i>=2){
      fnl[i]=fnl[i-1]+fnl[i-2];
    };
  }
  cout<<"Los primeros "<<nf1<<" numeros de la sequencia de fibonacci para el algoritmo de lista son: ";
  for(int i=0;i<nf1;i++){
    cout<<fnl[i]<<endl;
  }
}

int vectorfibo(int nf2){
  vector<int> vfibo;
  int confibo;
  for(int i=0;i<nf2;i++){
    if(i==0){
      confibo=0;
      vfibo.push_back(confibo);
    }
    if(i==1){
      confibo=1;
      vfibo.push_back(confibo);
    }
    if(i>=2){
      confibo=vfibo[i-1]+vfibo[i-2];
      vfibo.push_back(confibo);
    }
  }
    cout<<"Los primeros "<<nf2<<" numeros de la secuencia de fibonacci para el algoritmo de vectores son: ";
    for(int i=0;i<nf2;i++){
      cout<<vfibo[i]<<endl;
    }
}
int main(){
  int nf;
  cout<<"Ingrese la cantidad total de números de la secuencia que desea calcular"<<endl;
  cin>>nf;
  listafibo(nf);
  vectorfibo(nf);
}

