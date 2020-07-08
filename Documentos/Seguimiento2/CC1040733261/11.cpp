/*7.2-11. Modifique el programa escrito para el ejercicio 10 para buscar la 
primera ocurrencia de una secuencia de caracteres introducida por el 
usuario y reemplazar esta secuencia, cuando se encuentre en la cadena, 
con un segundo conjunto de una secuencia introducida por el usuario. 
Por ejemplo, si la cadena introducida es: La figura 4-4 ilustra la 
salida del programa 4-2 y el usuario introduce que 4- sea reemplazado 
por 3-, la cadena resultante será: La figura 3-4 ilustra la salida del 
programa 4-2. (Sólo se ha cambiado la primera ocurrencia de lo buscado 
en la secuencia.)*/
#include <iostream>
#include <string>//incluye todos los comandos que involucran las cadenas 
using namespace std;

void busyrem(string& str, string bus, string rem); //prototipo de una función donde se busca caracter y se encuentra otro 

void busyrem(string& str1, string bus, string rem){//creacion de la función donde se creó la busqueda y el reemplazo
	//str1=es la cadena bus=parametro a buscar, rem=carácter a reemplazar 
	int pos=str1.find(bus);//pos es la variable que se utiliza para buscar la posición que se quiere reemplazar
	if(pos!=-1){// si se encontro esta posioción el resultado de pos es igual a -1 ya que la posición va desde cero hasta donde se termine la cadena 
		//solo hasta que lo encuentre una vez 
		str1.replace(pos,bus.size(),rem);/*este remplaza apartir de la posicion donde se encontro el caracter, palabra o parte de la palabra que se pidio buscar
		en pos. Para saber el tamaño de lo que se manda a buscar se introduce el bus.size() y por ultimo el caracter que remplaza como rem*/
		
	}
	return;
}

int main(){
	string str;//cadena 
	string a; //carácter de búsqueda
	string b; //carácter de reemplazo
	cout<<"Introduzca texto:\n"<<endl;
	getline(cin, str);
	cout<<"Introduzca el carácter que quiere reemplazar"<<endl;
	getline(cin, a);
	cout<<"Introduzca el carácter por el que va a reemplazar"<<endl;
	getline(cin, b);
	busyrem(str, a, b);//llama la función busyrem que se pone a reemplaza en la cadena str; a por b
	cout<<str<<endl;
	return 0;
}

