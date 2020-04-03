//A continuación se realizan todos los puntos, corregidos del seguimiento que se entregó a la hora indicada y en un mismo archivo además de realizarse con vectores y listas, el objetivo más allá de una calificación distinta es mostrar que se cuenta los conocimientos que implicitamente busca el curso tenga uno.


//Librerias
#include<iostream>
#include<string.h>
#include<iomanip>
#include<vector>

using namespace std;

//Inicia el programa
int main(){
  int Ncai,Nca,cl,i;
  cout<<"Ingrese el número total de cadenas o parrafos que ingresará: "<<endl; //Para calcular el tamaño del arreglo
  cin>>Ncai;
  Nca=Ncai+1;
  string palabras[Nca],palabrasx[Nca]; //Arreglos de palabras ingresadas y reemplazadas
  cout<<"Ingrese las cadenas o parrafos que desea almacenar separadas por enter "<<endl;
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


  int elect;
  cout<<"Digite 0 si quiere reemplazar caracteres individuales, o digite 1 si quiere reemplazar bloques completos "<<endl;
  cin>>elect;
  if(elect==0){
    int ncaracn,cc;
    char carac,caracn;
    vector<char> incar;
    vector<char> incarn;
    vector<string> pacar;
    cout<<"Digite la cantidad de caracteres que piensa reemplazar: ";
    cin>>ncaracn;
    cout<<"Digite los caracteres que piensa reemplazar: ";
    for(i=0;i<ncaracn;i++){
      cin>>carac;
      incar.push_back(carac);
    }
    cout<<"Digite los caracteres nuevos que quiere en lugar de los que serán reemplazados: ";
    for(i=0;i<ncaracn;i++){
      cin>>caracn;
      incarn.push_back(caracn);
    }
    for(i=0;i<Nca;i++){
      cc=int(palabras[i].length());
      string palabracc=palabras[i];
      for(int j=0;j<cc;j++){
	for(int k=0;k<incar.size();k++){
	  if(palabracc[j]==incar[k]){
	    palabracc[j]=incarn[k];
	  }
	}
      }
      pacar.push_back(palabracc);
      cout<<setw(cc+2)<<pacar[i]<<endl;
    }
  }
  if(elect==1){
    int elect2;
    string palr,paln;
    cout<<"Ingrese la palabra o cadena de caracteres que quiere reemplazar: ";
    cin>>palr;
    cout<<"Ingrese la palabra o cadena de caracteres nueva que reemplazaran a la anterior: ";
    cin>>paln;
    cout<<"Digite 0 si desea reemplazar solo la primer cadena de caracteres, de cada cadena, o 1 si desea que sean todas"<<endl;
    cin>>elect2;
    if(elect2==0){
      for (i=0;i<Nca;i++){
	while(palabras[i].find(palr)!=string::npos){
	palabras[i].replace(palabras[i].find(palr),palr.length(),paln);
	cout<<"La cadena "<<i <<" reemplazada queda así: "<<endl;
	cout<<palabras[i]<<endl;
	break;
	}
      }
    }
    if(elect2==1){
      for (i=0;i<Nca;i++){
	while(palabras[i].find(palr)!=string::npos){
	  palabras[i].replace(palabras[i].find(palr),palr.length(),paln);
	}
	cout<<"La cadena "<<i<<" reemplazada queda así: "<<endl;
	cout<<palabras[i]<<endl;
      }
    }
  }
}

