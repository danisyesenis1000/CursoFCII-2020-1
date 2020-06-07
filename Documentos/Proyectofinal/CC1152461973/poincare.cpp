#include<iostream>
#include<iomanip>
#include<cmath>
#include <fstream>
#include <cstdlib>

using namespace std;
void LeerArchivo(string&);

int main(){
  string nombre_archivo;
  nombre_archivo="datos.dat";
  LeerArchivo(nombre_archivo);
}

void LeerArchivo(string& narchivo){
  ifstream poincarem;
  poincarem.open(narchivo.c_str());

  //Comprueba apertura del archivo
  if (poincarem.fail()){
    cout <<"\n El archivo no se abrió con éxito"
	 <<"\n Compruebe que dicho archivo sí existe"
	 << endl;
    exit(1);
  }
  double matrix[30000][3];
  for(int i=0;i<30000;i=i+1){
    for(int j=0;j<3;j=j+1){
      poincarem>>matrix[i][j];
    }
  }
  poincarem.close();
  /*
  int ofs[51];
  for(int i=0;i<51;i=i+2){
    ofs[i]=i;
  }
  */
  int N=400;
  int S=100;
  int P=100;
  int indm=(N-S)*P;
  /*
  for(int i=0;i<51;i=i+1){
    indm[i]=((N-S)*P-ofs[i]);
  }
  */
      
  string archivopon = "datos1.dat";
  ofstream archivo_pon;
  archivo_pon.open(archivopon.c_str());
  if (archivo_pon.fail()){
    cout <<"El archivo no se abrió exitosamente"<<endl;
    exit(1);
  }
   //Formato de los datos
  archivo_pon << setiosflags(ios::fixed);
  
  double l_t[N-S];
  double l_o[N-S];
  for(int j=0;j<indm;j=j+P){
    l_t[j]=matrix[j][1];
    l_o[j]=matrix[j][2];
  }
   for(int j=0;j<indm;j=j+P){
     archivo_pon<<l_t[j]<<"   ";
     archivo_pon<<l_o[j]<<"\n";
   }
   archivo_pon.close();
}
