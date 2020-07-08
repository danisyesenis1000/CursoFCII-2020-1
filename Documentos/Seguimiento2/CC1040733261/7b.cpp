/*8.2-7. Escriba un programa en C++ que lea el archivo de datos creado 
en el ejercicio 7a y calcule y despliegue una lista de nómina. 
La salida deberá enlistar el número de seguro social, nombre, pago 
bruto para cada individuo y donde el pago bruto se calcula se hará 
como tarifa por hora x horas trabajadas.*/
#include <iostream>
#include <fstream>
#include <cstdlib> // necesario para exit()
#include <string>
#include <iomanip>

using namespace std; 

int main(){
	string nomarc= "texto.txt"; // pone al frente el nombre de archivo
	string nombre; //nombre
	string nuseso; //numero de seguro social
	double tapoho; //tarifa por hora
	double hotr; //horas trabajadas
	
	ifstream arcent;
	
	arcent.open(nomarc.c_str());
	
	if(arcent.fail()){//comprueba el éxito en la apertura
		cout<<"\nEl archivo no se abrió con éxito"
            <<"\n Por favor compruebe que el archivo existe en realidad."
            <<endl;
        exit(1);
	}
	cout<<setw(12)<<"Nombre"<<setw(28)<<"Número de seguro social"<<setw(14)<<"Pago bruto"<<endl;
	//lee y despliega el contenido del archivo
	arcent>>nombre>>nuseso>>tapoho>>hotr;
	while(arcent.good()){// comprueba el siguiente carácter
		
		cout<<setw(12)<<nombre<<setw(20)<<nuseso<<setw(19)<<tapoho*hotr<<endl;
		
		arcent>>nombre>>nuseso>>tapoho>>hotr;
		
	
	}
		
	arcent.close();
	
	return 0;
}
	
	
