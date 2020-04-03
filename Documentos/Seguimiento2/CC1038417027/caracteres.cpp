#include <iostream>
#include <string>

using namespace std;

void reemplazo()//ejercicio 10
{
  string str1;
  cout<<"Ingrese la frase que desea reemplazar (tenga en cuenta que reemplazara las e por las x)"<<endl;
  getline(cin,str1);
  cout<<"\n-------------------------------\n"<<endl;
  string str2="e"; //Para verificar el reemplazo 
  cout<<"La cadena sin modificar es: "<<str1<<endl; 
  for (int i=0;i<=int(str1.length());i++)
    {
      
      if (str1[i]==str2[0]){
	str1.replace(i,1,"x");
      }
    }
  cout<<"La cadena modificada es: " <<str1<<endl;
  cout<<"\n-------------------------------\n"<<endl;
}

void reemplazoPorUsuario() //ejercicio 11
{
  //cadena 1 es la cadena a la que le ingresamos el texto
  //cad1 es lo que deseamos reemplazar
  //rem1 es por lo que el usuario desea reemplazar
  string cadena1, cad1,rem1;

  cout<<"Ingrese la cadena"<<endl;
  getline(cin,cadena1);
  cout<<"\n-------------------------------\n"<<endl;
  cout<<"Ingrese la o las palabras de la cadena que desea reemplazar"<<endl; 
  getline(cin,cad1);
  cout<<"Ingrese la o las palabras por la  que se reemplazara"<<endl;
  getline(cin,rem1);
  cout<<"\n-------------------------------\n"<<endl;
  int k = int(cadena1.find(cad1));
  int n = int(cad1.length());
  cadena1.replace(k,n,rem1);
  cout<<"La cadena reemplazada es: "<<cadena1<<endl;
}

void reemplazoTotal() //ejercicio 12
{
  string cadena1;
  string cad1;
  string rem1;

  cout<<"Ingrese la cadena de caracteres"<<endl;
  getline(cin,cadena1);
  cout<<"\n-------------------------------\n"<<endl;
  cout<<"Ingrese la o las palabras a reemplazar"<<endl;
  getline(cin,cad1);
  cout<<"Ingrese la o las palabras que reemplazara"<<endl;
  getline(cin,rem1);
  cout<<"\n-------------------------------\n"<<endl;
  int n = int(rem1.length());
  int b = int(cadena1.length());
  int j = int(cadena1.find(cad1));
  
  
  for (int i=0;i<b;i++)
    {
      j=int(cadena1.find(cad1));
      if (j==-1)break;
      else{
	cadena1.replace(j,n,rem1);
      }
      
      
    }
  cout<<"La cadena modificada es: "<<cadena1<<endl;
}
int main() {
  cout<<"-------------------------------------------------\n"<<endl;
  cout<<"Ejercicio 10 del libro"<<endl;
  reemplazo();
  cout<<"-------------------------------------------------\n"<<endl;
  
  cout<<"Ejercicio 11 del libro"<<endl;
  reemplazoPorUsuario();
  cout<<"-------------------------------------------------\n"<<endl;
  cout<<"Ejercicio 12 del libro"<<endl;
  reemplazoTotal();
  cout<<"-------------------------------------------------\n"<<endl;
  return 0;
}
