/*1. Para jugar al ahorcado escriba un programa . El programa debe 
elegir una palabra (que se codifica directamente en el programa) y 
mostrar lo siguiente:
adivine la palabra: xxxxx 
cada x representa una letra. El usuario tratara de adivinar las letras 
en la palabra. Debera mostrarce la respuesta apropiada (si la letra 
pertenece o no) despues de cada intento. Si la letra pertenece a la 
palabra buscada dele la opotunidad de adivinar si el desea. Despues de
siete intentos incorrectos (ya sean palabra o letras) el usuario sera 
colgado.
Gane o pierda dele la opcion al usuario de jugar de nuevo.*/

#include <iostream>
#include <string>//para tener cadenas de palabras en este caso desde un archibo txt
#include <vector>// para poder hacerun arreglo con tamaño variable
#include <fstream>//cadenas de palabras 
using namespace std;

//se hacen 4 variables generales
string palori;//aqui se almacena la palabra original que el jugador esta adivinando
string palmos;//lo que realmente el programa muestra en la pantalla 
int vid; //numero de vidas
int al;//numero aleatorio

//funciones 
void mos();//mostrar la palabra, cuantas vidas se tiende y espera que el usuario ingrese un caracter
void ing(char x);//coje la palabra original  y donde tenga el caracter x lo cambia 
void ini();//funcion inicializar de la palabra original, palabra mostrar y las vidas
void eje();//eje del juego
string palale();//función para traer una palabra aleatoria


void eje(){//desarrollo del eje del juego 
	ini();//llamado de la función inicializar
	mos();//llamado de la función mostrar
	
	while(vid>0 && palmos!=palori){ //mientras las vides sean mayores que cero  y la palabra mostrada sea diferente a la palabra original 
		char x;//llama caracteres
		cin>>x;//recibe el carácter
		ing(x);//ingresar carácter 
		mos(); //mostrar la cadena
	}
	//salir del sel ciclo while puede ser por dos cosas; ganar o perder
	if (vid>0)
		cout<<"GANASTE"<<endl;
	
	else if (vid==0)
		cout<<"PERDISTE, la palabra que no pudiste adivinar es: "<<palori<<endl;
					
}


int main(){//aquí se ejecuta el juego y se trato de hacer el ciclo para jugar y bolver a jugar o salir pero no funciono :S para salir del juego sip
	ini();
	eje();
	int a;
	cout<<"si quiere jugar marca 0 si no marca 1"<<endl;
	cin>>a;
	if  (a==0){	    
		eje();
		cout<<"si quiere seguir jugando marca 0 si no marca 1"<<endl;
		cin>>a;
	}
	else{ 
			cout<<"gracias por jugar"<<endl;
		}
		
	return 0;
}

void mos(){//desarrollo mostrar la palabra, cuantas vidas se tiende y espera que el usuario ingrese un caracter
	cout<<"recuerda que esta palabra solo será en minúsculas"<<endl;
	cout<<"Tienes "<<vid<<" vidas"<<endl;
	cout<<palmos<<endl;
}

void ini(){//inicialización del juego
	int i,b;
	b=palori.length();//largo en caracteres de la palabra
	vid=7;
	palori=palale();//palabra escogida aleatoriamente de la lista de palabras
	
	for(i=0; i<b; i++){ //itera sobre todos los caracteres 
		//hacer los guiones que determinan la cantidad de letras de la palabra originial 
		if (palori[i]>='a' && palori[i]<='z'){//es una letra minuscula 
			palmos+='x';
		}
	}
}
	void ing(char x){//ingresa caracteres	
		int i,b;
		b=palori.length();
		double pervid=true;//es verdadero si se pierde una vida 
		for (i=0; i<b; i++){//itera sobre todos los caracteres
			if(x==palori[i]){//si la letra es igual a alguna letra dentro de la palabra original 
				pervid=false;//si se entra a este if no se perdieron vidas 
				palmos[i]=x;//cambia el x por la letra en la posicion correspondiente 
			}
		 }
		 if(pervid==true){//como la letra no esta en la palabra
			 vid--;//se pierde una vidas 
		 }

}

vector<string> lispal(){//para la lista de palabras, que gracias a vector estas pueden ser de longitud variable. puedo poner aqui un archivo txt que tenga una cantidad diferente de palabras 
	vector<string> pals;
	ifstream arcpals("par2pals.txt");//aquí se abre el archivo de palabras 
	string pal;
	
	while (arcpals>>pal){//para tomar del archivo una palabra
		pals.push_back(pal);//con pals esta sera aleatoria 
		
	}
	arcpals.close(); //cerrando el archivo de palabras
	
	return pals;	
} 


string palale(){
	//del conjunto de palabras se escoge una al azar
	vector<string> pals=lispal();//lista de palabras
	srand(time(0));
	al=rand()%(pals.size()+1);//palabra aleatoria 
	//cout<<al<<" "<< pals.size()<<endl; ayuda para ve la palabra escogida aleatoriamente en la salida

    return pals[al];  
}
		
