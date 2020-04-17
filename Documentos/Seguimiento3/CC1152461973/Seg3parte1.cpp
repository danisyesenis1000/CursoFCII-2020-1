#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <iomanip>
#include <string>

using namespace std;

void creacion()
{
 ofstream archivo; //asi llamo al archivo dentro del codigo
 archivo.open("Datos.txt", ios::out); //creo el archivo.txt 
 if (archivo.fail()) //para garantizar que si esté bien escrito
 {
    cout<< "El archivo no pudo ser creado"<< endl;
    exit(1);
 }
 
 string Nombre[4]={"B Caldwell","D Memcheck","R Potter","W Rosen"};
 string Numero[4]={"555-88-2222","555-77-4444","555-77-6666","555-99-8888"};
 double Tarifa[4]={7.32,8.32,6.54,9.80};
 int Horas[4]={37,40,40,35};
 for (int i = 0; i<4; i++)
 {
     archivo<< Nombre[i]<<" "<< Numero[i]<<" "<< setiosflags(ios::showpoint)<<setprecision(3) << Tarifa[i]<<" "<<Horas[i]<<endl;
 }

  archivo.close();
}

void nomina(ifstream& archivo_entrada)
{
 string nombre,apellido, seguro_social;
 double tarifa, pago;
 int horas;
 cout<<left << setw(12)<<"Nombre "<<setw(11)<<"| Número de seguro social "<<"| Tarifa por hora trabajada "<<"| Horas trabajadas "<<"| Pago bruto "<<endl;
 cout<<endl;
 while (archivo_entrada.good()) //mientras no se haya llegado al final del archivo haga lo siguiente
 {
     archivo_entrada>> nombre >> apellido >> seguro_social >> setiosflags(ios::fixed) >> setiosflags(ios::showpoint) >> setprecision(2)>> tarifa >> horas;
     pago = tarifa*horas;
     
     cout<<left<< setw(2)<< nombre << setw(10)<< apellido <<"| "<< setw(23)<< seguro_social<<" | "<<setw(26)<< tarifa <<"| "<<setw(16)<< horas <<" | " << setiosflags(ios::fixed)<<setiosflags(ios::showpoint)<< setprecision(2)<< pago << endl;
 }
 archivo_entrada.close();
}
//Usando el archivo creado mostrar los datos de la nómina y el pago bruto de cada uno. 
int main()
{ 
    string nom_archivo = "Datos.txt";
    creacion();
    ifstream entrada(nom_archivo.c_str(), ios::in); //ese c_str() convierte en un objeto de cadena el archivo
    if (entrada.fail()) //comprobamos que abrió con éxito
    {
        cout<<"Revise si el archivo existe o si se encuentra en la dirección apropiada"<< endl;
        exit(1);
    }
    nomina(entrada);
    return 0;
}
