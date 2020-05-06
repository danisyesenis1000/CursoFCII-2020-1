#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

void LeerArchivo(string&);

int main(){
  string nombre_archivo;
  nombre_archivo="nomina.dat";
  cout<<"Nombres   Seguridad Social   Pago por hora   Horas trabajadas   Pago total\n";
  cout<<"________   ________________   _____________   ________________   ___________ \n";
  LeerArchivo(nombre_archivo);
  
}

void LeerArchivo(string& narchivo){
  string nombre1,nombre2,sec_social;
  double phoras,horas,saltrab;
  ifstream nomina_calculo;
  nomina_calculo.open(narchivo.c_str());

  //Comprueba apertura del archivo
  if (nomina_calculo.fail()){
    cout <<"\n El archivo no se abrió con éxito"
	 <<"\n Compruebe que dicho archivo sí existe"
	 << endl;
    exit(1);
  }
  nomina_calculo>> nombre1>>nombre2>> sec_social >> phoras>> horas;
  while (nomina_calculo.good()){//evalua la existencia de caracteres
    saltrab=phoras*horas;
    cout << nombre1 <<' '<<nombre2<<' '<<' '<<' '<< sec_social <<setw(16)<< phoras <<setw(16)<< horas <<setw(18)<<saltrab<< endl;
    nomina_calculo>> nombre1 >>nombre2>> sec_social >> phoras>> horas;
      }
  //inFile.close();

  nomina_calculo.close();
}
