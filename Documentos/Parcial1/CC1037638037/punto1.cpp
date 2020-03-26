#include <iostream>
#include <stdlib.h>

using namespace std;
int main(){
	srand (time(NULL));
	bool run=1;

	while(run){

		int r=rand() % 1000 + 1; 
		int in=-1;
		
		cout<<"Adivine el numero del 1 al 1000"<<endl;
		while(r!=in){
			cout<<"Ingrese un numero"<<endl;
			cin>>in;

			if(r==in){
				string res;
				cout<<"GANO!"<<endl;
				cout<<"¿desea seguir jugando? (si/no)"<<endl;
				cin>>res;
				if(res=="si")
					run=1;
				else
					run=0;
			}
			else{
				
				if(r<in)
					cout<<"Numero equivocado, es un numero menor"<<endl;
				if(r>in)
					cout<<"Numero equivocado, es un numero mayor"<<endl;
			}
		}
	}	
}