/*8-aCree un archivo de texto que contenga los siguientes datos 
(sin los encabezados):*/ 
#include <iostream>
#include <fstream>
#include <cstdlib> // necesario para exit()
#include <string>//escribir datos en forma de cadena 
#include <iomanip>// para poner los datos bien organizados 

using namespace std;
 
void escribir();//prototipo de una función que sirve para  escribir o 
//crear datos en un archibo de  texto txt  

int main(){
	
	escribir();//llamar la función para crear el archibo de texto aqui
	
	return 0;
}

void escribir(){
	ofstream archivo;//describe el texto; para esto se usa el tipo de dato ofstream con variable archivo 
	
	archivo.open("texto.txt",ios::out);/*abre el archivo con .open 
	dentro del paréntesis está primero el nombre ya: sea .txt o .dat 
	etc, y despues de la como esta el modo como se usará el archivo;
	para este caso se copiará dentro de este. Así ios::out; escribe 
	dentro de este si este existe, pero si no existe lo crea con el 
	el nombre propuesto*/
	
	if(archivo.fail()){//verifica si se crea o existe 
		cout<<"No se pudo abrir el archivo";
		exit(1);//sale automaticamente 
	}
	
	//en archivo se introducen los datos pedidos 
	archivo<<setw(11)<<"BCaldwell"<<setw(13)<<"555882222"<<setw(6)<<7.32<<setw(4)<<37<<endl
           <<setw(11)<<"DMemcheck"<<setw(13)<<"555774444"<<setw(6)<<8.32<<setw(4)<<40<<endl
	       <<setw(11)<<"RPotter"<<setw(13)<<"555776666"<<setw(6)<<6.54<<setw(4)<<40<<endl
	       <<setw(11)<<"WRosen"<<setw(13)<<"555998888"<<setw(6)<<9.80<<setw(4)<<35<<endl;
	        
	
	archivo.close(); //cerrar el archivo
}
	
	

