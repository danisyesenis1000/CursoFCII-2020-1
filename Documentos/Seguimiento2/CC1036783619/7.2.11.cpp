/*Problema 11: Modifique el programa escrito para el ejercicio 10 para buscar la primera ocurrencia
de una secuencia de caracteres introducida por el usuario y reemplazar esta
secuencia, cuando se encuentre en la cadena, con un segundo conjunto de una secuencia
introducida por el usuario. Por ejemplo, si la cadena introducida es La figura
4-4 ilustra la salida del programa 4-2 y el usuario introduce que
4- sea reemplazado por 3, la cadena resultante será La figura 3-4 ilustra
la salida del programa 4-2. (Sólo se ha cambiado la primera ocurrencia de
lo buscado en la secuencia.) */

#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

int main(){
	int longitud, i; //Declara variables
	string caracter, reemplazable, reemplazo, borrado; //Se declara el caracter
	cout<<"Digite un caracter : "<<endl;
	getline(cin, caracter); //Asigna entrada al caracter
	cout<<"Digite reemplazable: "<<endl;
	getline(cin, reemplazable);
	cout<<"Digite reemplazo: "<<endl;
	getline(cin, reemplazo);	
		
	i=caracter.find(reemplazable); //Es la posicion en la cual esta el reemplazable
	caracter.erase(i,reemplazable.length()-1);
	caracter.replace(i,1,reemplazo);  //Reemplaza 
			
	cout<<"-----------------------------------"<<endl;
	cout<<"El caracter modificado es: "<<endl;
	cout<<caracter;
	
	getch(); // Evita que el ejecutable se cierre
	return 0;
}
