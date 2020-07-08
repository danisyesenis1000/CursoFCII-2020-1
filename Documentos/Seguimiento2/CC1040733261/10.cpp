/*7.2- 10. Escriba un programa en C++ que acepte una cadena 
del usuario y luego reemplace todas las ocurrencias de la letra e con 
la letra x. */
#include <iostream>
#include <string>//incluye todos los comandos que involucran las cadenas 
using namespace std;

void busyrem(string& str1, string bus, string rem); //prototipo de una función donde se busca caracter y se encuentra otro 

void busyrem(string& str1, string bus, string rem){//creacion de la función donde se creó la busqueda y el reemplazo
	//str1=es la cadena bus=parametro a buscar, rem=carácter a reemplazar 
	int pos=str1.find(bus);//pos es la variable que se utiliza para buscar la posición que se quiere reemplazar
	while(pos!=-1){//mientras  se encuentre esta posición el resultado de pos es diferente a -1 ya que la posición va desde cero hasta donde se termine la cadena
		//while crea el ciclo que barre toda la cadena junto con la variable **
		str1.replace(pos,bus.size(),rem);/* este remplaza apartir de la posicion donde se encontro el caracter, palabra o parte de la palabra que se pidio buscar
		en pos. Para saber el tamaño de lo que se manda a buscar se introduce el bus.size() y por ultimo el caracter que remplaza como rem*/
		pos=str1.find(bus,pos+rem.size());//**esto lo que hace es buscar y reemplazar a partir de la ultima pocicon donde encontro la el parametro pedido
	}
	return;
}

int main(){
	string str;//cadena
	cout<<"Introduzca texto:\n"<<endl;
	getline(cin, str);//introducción de la cadena 
	busyrem(str, "e", "x"); //llama la función busyrem que se pone a reemplazar en la cadena str; e por x
	cout<<str<<endl;//salida
	return 0;
}
