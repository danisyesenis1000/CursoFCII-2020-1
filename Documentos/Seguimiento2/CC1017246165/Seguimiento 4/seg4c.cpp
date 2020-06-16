//A continuación se realiza el punto 12

//Libreria
#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

int main(){
  int Ncai,Nca,cl,i,cr;
  cout<<"Ingrese el número total de cadenas que ingresará"<<endl; //Para calcular el tamaño del arreglo
  cin>>Ncai;
  Nca=Ncai+1;
  cout<<"Ingrese el número total de caracteres a reemplazar que ingresará "<<endl; //Para calcular el tamaño del arreglo
  cin>>cr;
  char caracteres[cr],caracteresn[cr];
  string palabras[Nca],palabrasx[Nca]; //Arreglos de palabras ingresadas y reemplazadas
  cout<<"Ingrese el conjunto de palabras que desea almacenar separadas por un espacio"<<endl;
  for(i=0;i<Nca;i++){  //Se ingresa cada palabra en cada parte del arreglo
    getline(cin,palabras[i]);
  }
  i=0;
  cout<<"Introduzca las ocurrencias que desea reemplazar: ";
  while(i<cr){
    cin>>caracteres[i];
    i=i+1;
  }
  i=0;
  cout<<"Introduzca el caracter que reemplazará dicha ocurrencia en orden: ";
  while(i<cr){
    cin>>caracteresn[i];
    i=i+1;
  }
  cout<<"las palabras con el caracter o los caracteres reemplazados, quedan de la siguiente manera: "<<endl;
  for(i=0;i<Nca;i++){  //Se reemplaza la letra evaluando cada caracter de cada palabra
    cl=int(palabras[i].length());
    string palabrai=palabras[i];
    for(int j=0;j<cl;j++){
      for(int k=0;k<cr;k++){
	if (palabrai[j]==caracteres[k]){ //El problema no especifícia si también la E mayúscula, por eso no uso el ||
	  palabrai[j]=caracteresn[k];
	}
      }
    }
    palabrasx[i]=palabrai;
    cout<<setw(cl+2)<<palabrasx[i];
  }
  cout<<endl;
  return 0;
}
