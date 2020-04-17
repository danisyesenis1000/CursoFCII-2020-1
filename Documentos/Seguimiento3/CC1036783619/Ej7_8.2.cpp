#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

//prototipos de las funciones que escriben y leen el archivo
void write();
void read(string&);

//implementacion de la escritura y lectura
int main(){
	string file_in;
	write();
	file_in="Datos.dat";
	cout<<"Nombre    Seguridad Social   Pago por hora  Horas trabajadas   Total a pagar\n";
	cout<<"--------- ----------------  -------------  -------------------   -----------\n";
	read(file_in);
	
	return 0;
}
//funcion que escribe el archivo
void write(){
	
	string file_name="Datos.dat"; //se especifica el nombre del archivo
	ofstream file;
	
	file.open(file_name.c_str()); //se crea
	
	if(file.fail()){  //garantiza que si hay error en escritura, lo haga saber
		cout<<"El archivo no se pudo abrir";
		exit(1);
	}
	
	//se entran los datos
	file<< setiosflags(ios::fixed)
		<< setiosflags(ios::showpoint)
		<< setprecision(2);
		
	file <<"B Caldwell "<<"555-88-2222 "<<7.32<<"   "<<37<<endl
		 <<"D Memcheck "<<"555-77-4444 "<<8.32<<"   "<<40<<endl
		 <<"R Potter   "<<"555-77-6666 "<<6.54<<"   "<<40<<endl
		 <<"W Rosen    "<<"555-99-8888 "<<9.80<<"   "<<35<<endl;
		
	file.close();
	
}

//funcion que lee los datos
void read(string& file){
  //declaracion de las variables
  string name,wspace,social_sec;
  double hour_payment;
  double work_time;
  double total;
  
  //abre el archivo para leerlo
  ifstream file_in;
  file_in.open(file.c_str());

  //garantiza que si hay error de lectura lo haga saber y se detenga
  if (file_in.fail()){
    cout <<"\n El archivo no se abrió con éxito"
	 <<"\n Compruebe que dicho archivo sí existe"
	 << endl;
    exit(1);
  }
  //se leen los datos linea a linea y se asignan a variables declaradas anteriormentre
  file_in>> name>>wspace>> social_sec >> hour_payment>> work_time;
  while (file_in.good()){
    total=hour_payment*work_time; //calculo del total a pagar
    cout<<name<<' '<<wspace<<' '<<' '<<' '<<social_sec<<setw(12)<<hour_payment<<setw(18)<< work_time<<setw(20)<<total<<endl;
    file_in>>name>>wspace>>social_sec>>hour_payment>>work_time;
      }


  file_in.close();
}
