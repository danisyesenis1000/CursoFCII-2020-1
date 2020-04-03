#include <iostream>
using namespace std;
 
int main(){
	int a,b,c,d; //se declara el numero del juego, el numero del usuario y un numero adicional para el condicional para repetir el juego	
	c=0;
	while(c==0){
		srand(time(NULL)); // para generar el numero aleatorio
		a=1+rand()%(1000); //genera numero aleatorio entre 1 y 1000
		while(a!=b){
			cout<<"Elige un numero:  "; cin>>b; //el usuario elige el numero
			if (b<1 or b>1000){              //si el usuario elige un numero por fuera de los valores validos se interrumpe su ejecucion
				cout<<"\n Debe ser un numero entre 1 y 1000... :/ \n";
				exit(-1);
			}
				
			if (a<b){ //condicion por si el numero elegido es mayor al que se busca
				cout<<"\nEl numero que elegiste es mayor\n";
			}
			if (a>b){ //condicion por si el numero elegido es menor al que se busca
				cout<<"\nEl numero que elegiste es menor\n";
			}
		    if (a==b){ //condicion ganadora
		    cout<<"\n¡Ganaste!\n";
			}
		}	  
		cout<<"\nPara jugar de nuevo presiona 1, si no, presiona otra tecla\n"; //pregunta si quiere jugar de nuevo para reiniciar el ciclo
		cin>>d;
		if (d!=1){ //si no quiere jugar de nuevo, cierra el ciclo
			break;
		}
	}
	cout<<"¡Vuelve pronto!"<<endl;
	return 0;
}
