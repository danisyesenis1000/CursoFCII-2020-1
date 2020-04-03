//A continuación se realiza el punto 10


//Librerias
#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

//Inicia el programa
int main(){
  int Ncai,Nca,cl,i;
  cout<<"Ingrese el número total de cadenas que ingresará"<<endl; //Para calcular el tamaño del arreglo
  cin>>Ncai;
  Nca=Ncai+1;
  string palabras[Nca],palabrasx[Nca]; //Arreglos de palabras ingresadas y reemplazadas
  cout<<"Ingrese las cadenas que desea almacenar separadas por enter "<<endl;
  for(i=0;i<Nca;i++){  //Se ingresa cada palabra en cada parte del arreglo
    getline(cin,palabras[i]);
      }
  cout<<"Las cadenas que usted ingreso fueron: "<<endl;
  for(i=0;i<Nca;i++){
    cout<<setw(int(palabras[i].length())+2)<<palabras[i]<<endl; //Se imprimen las palabras que ingresó el usuario
  }
  cout<<endl;
  cout<<"las cadenas con la letra 'e' reemplazada por la 'x' quedan de la siguiente manera: "<<endl;
  for(i=0;i<Nca;i++){  //Se reemplaza la letra evaluando cada caracter de cada palabra
    cl=int(palabras[i].length());
    string palabrai=palabras[i];
    for(int j=0;j<cl;j++){
      if (palabrai[j]=='e'){ //El problema no especifícia si también la E mayúscula, por eso no uso el ||
	palabrai[j]='x';
      }
    }
    palabrasx[i]=palabrai;
    cout<<setw(cl+2)<<palabrasx[i]<<endl;
    }
  cout<<endl;
  return 0;
}
