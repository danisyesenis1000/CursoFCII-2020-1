/*Problema 10: Escriba un programa en C++ que acepte una cadena del usuario y luego reemplace
todas las ocurrencias de la letra e con la letra x.*/

#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

int main(){
	int longitud, i; //Declara variables
	string caracter; //Se declara el caracter
	cout<<"Digite un caracter : "; 
	getline(cin, caracter); //Asigna entrada al caracter
	
	i=caracter.find("e"); //Es la posicion en la cual esta "e"
	while (i!=string::npos){ 
		caracter.replace(i,1,"x");  //Reemplaza en la posicion de e por una x
		i=caracter.find("e", i+1); //Busca en el siguiente caracter
	}	
	cout<<"-----------------------------------------------"<<endl;
	cout<<"El caracter modificado es: "<<endl;
	cout<<caracter;
	
	getch(); // Evita que el ejecutable se cierre
	return 0;
}
