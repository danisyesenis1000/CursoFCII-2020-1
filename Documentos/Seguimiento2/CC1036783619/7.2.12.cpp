/*Problema 12: Modifique el programa escrito para el ejercicio 11 para reemplazar todas las ocurrencias
de la secuencia de caracteres designada con la nueva secuencia de caracteres. Por
ejemplo, si la cadena introducida es La figura 4-4 ilustra la salida del
programa 4-2 y el usuario introduce que 4 ha de ser reemplazado por 3, la cadena
resultante será La figura 3-4 ilustra la salida del programa 3-2.*/

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
	getline(cin, reemplazable); //Asigna lo que se reemplazara
	cout<<"Digite reemplazo: "<<endl;
	getline(cin, reemplazo);	//Asigna por lo que se reemplazara
		
	i=caracter.find(reemplazable); //Es la posicion en la cual esta el reemplazable
	while (i!=string::npos){ 
		caracter.erase(i,reemplazable.length()-1); //Borra desde la segunda posicion a la ultima del reemplazable
		caracter.replace(i,1,reemplazo);  //Reemplaza 
		i=caracter.find(reemplazable, i+1); //Busca en el siguiente caracter
		
	}	
	cout<<"-----------------------------------"<<endl;
	cout<<"El caracter modificado es: "<<endl;
	cout<<caracter;
	
	getch(); // Evita que el ejecutable se cierre
	return 0;
}
