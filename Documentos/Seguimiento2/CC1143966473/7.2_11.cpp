#include <iostream>
#include <iomanip> // Llamanos la funciones necesarias
#include <string>

using namespace std;

int main() // iniciao de la funcion main
{
  cout<<"==Reemplazar caracteres en un string==\n"<<endl;
  cout<<"Ingresa una linea de string= ";
  string cadena1;//("figura 4-4 ilustra la salida del programa 4-2");
  getline(cin, cadena1); // El usuario ingresa una cadena de caracteres
  cout<<endl;

  cout<<"-----------------------------"<<endl;
  cout<<"Ingresar el caracter que desea reemplazar con el siguiente formato:"<<endl;
  cout<<"'caracter a reemplazar' sea reemplazado por 'caracter por el cual reemplaza'."<<endl;

  cout<<"Ejemplo: karen sea reemplazado por natalia\n"<<endl;

  string cadena2;//("4- sea reemplazado por 3-");
  cout<<"Ingresa caracter= ";
  getline(cin, cadena2); // el usuario ingresa la cadena de caracteres a buscar
  int e1=cadena2.find(" sea"); // busca la palabra sea
  int e2=cadena2.find("por"); // busca la palabra por

  if(e1==-1 || e2==-1) // si no esta ningun de los caracteres
    {
      cout<<"NO tiene el formato que se pide para reemplazar."<<endl;
      cout<<"No se ha cambiado ningun carater en el string."<<endl;
    }
  else
    {
      string string1=cadena2.substr(0,e1); // encusntra la posicion de los caracteres
      string string2=cadena2.substr(e2+4,int(cadena2.length()));
       int posicion1 = cadena1.find(string1);

       if (posicion1==-1) // si no esta el estring a reemplazar
	{
	  cout<<string1<<" No esta en el string a reemplazar"<<endl;
	  cout<<"Favor intente nuevamente"<<endl;
	  cout<<"No se ha cambiado ningun carater en el string."<<endl;
	}
       else // reemplaza el string 
	{
	  cadena1.replace( posicion1,int(string1.length()) ,string2);
	}
    }
  //imprime el string final
  cout<<"\nEL string final es:"<<endl;
  cout<<cadena1<<endl;

  return 0;
}
