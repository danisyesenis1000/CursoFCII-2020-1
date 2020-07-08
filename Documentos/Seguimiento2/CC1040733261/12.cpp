/*7.2-12. Modifique el programa escrito para el ejercicio 11 para 
reemplazar todas las ocurrencias de la secuencia de caracteres designada
con la nueva secuencia de caracteres. Por ejemplo, si la cadena 
introducida es La figura 4-4 ilustra la salida del programa 4-2 y el 
usuario introduce que 4- ha de ser reemplazado por 3-, la cadena 
resultante será La figura 3-4 ilustra la salida del programa 3-2*/
#include <iostream>
#include <string>//incluye todos los comandos que involucran las cadenas 
using namespace std;

void busyrem(string& str, string bus, string rem); //prototipo de la función

void busyrem(string& str, string bus, string rem){//creacion de la función donde se creó la busqueda y el reemplazo
	//str1=es la cadena bus=parametro a buscar, rem=carácter a reemplazar 
	int pos=str.find(bus);//pos es la variable que se utiliza para buscar la posición que se quiere reemplazar
	while(pos!=-1){//mientras  se encuentre esta posición el resultado de pos es diferente a -1 ya que la posición va desde cero hasta donde se termine la cadena
		//while crea el ciclo que barre toda la cadena junto con la variable **
		str.replace(pos,bus.size(),rem);/* este remplaza apartir de la posicion donde se encontro el caracter, palabra o parte de la palabra que se pidio buscar
		en pos. Para saber el tamaño de lo que se manda a buscar se introduce el bus.size() y por ultimo el caracter que remplaza como rem*/
		pos=str.find(bus,pos+rem.size());//**esto lo que hace es buscar y reemplazar a partir de la ultima pocicon donde encontro la el parametro pedido
	}
	return;
}

int main(){
	string str;//cadena 
	string a; //carácter de búsqueda
	string b;//carácter de reemplazo
	cout<<"Introduzca texto:\n"<<endl;
	getline(cin, str);
	cout<<"Inctrodusca el caracter que quiere reemplazar"<<endl;
	getline(cin, a);
	cout<<"Introdusca el caracter por el que va a reemplazar"<<endl;
	getline(cin, b);
	busyrem(str, a, b);//llama la función busyrem que se pone a reemplaza en la cadena str; a por b
	cout<<str<<endl;
	return 0;
}
