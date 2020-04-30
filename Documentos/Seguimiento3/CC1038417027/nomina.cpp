#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


//numeral a) del ejercicio 
void ingreso()
{
  ofstream datos("nomina.txt");

  if(!datos)
    {
      cout<<"No se puede abrir el archivo"<<endl;
      exit(1);
    }

  //Instrucciones para el ingreso de datos
  cout<<"----------------------------------------------"<<endl;
  cout<<"A continuacion se le pedira ingresar los datos a ingresar en la nomina, por favor siga las instrucciones"<<endl;
  cout<<"----------------------------------------------"<<endl;
  cout<<"Ingrese los datos seguido de enter para su respectiva linea\n"
      <<"Para ingresar los datos debe separarlos por espacios y seguir el siguiente orden:\n"
      <<"Nombre (Solo primer nombre), numero de seguro social, tarifa por hora, horas trabajadas\n"
      <<"Cuando desee finalizar el ingreso de datos escriba 3 veces fin."<<endl;
  cout<<"----------------------------------------------"<<endl;
  
  char nombre[40];
  double tarifa,horas;
  string seguroSocial;

  while(cin>>nombre>>seguroSocial>>tarifa>>horas)
    {
      //para modificar el string del seguro social y aparesca como en el ejemplo
      seguroSocial.insert(3,"-");
      seguroSocial.insert(6,"-");
      //ingreso de datos en el documento 
      datos<<nombre<<' '<<seguroSocial<<' '<<tarifa<<' '<<horas<<endl;
    }
}



//numeral b) del ejercicio 
void mostrarDatosIngresados()
{
  ifstream archivo("nomina.txt");
  if ( archivo.fail() )   
    {
      cout << "El archivo no existe, primero cree la nomina y despues ejecute este comando" << endl;
      exit( 1 );
    }
  
  char nombre[40];
  double tarifa,horas;
  string seguroSocial;
  
  cout<<left<< setw(18) <<"Seguro social"<<setw(15)<<"Nombre"<<setw(18)<<"Pago bruto"<<endl;
  
  while (archivo>>nombre>>seguroSocial>>tarifa>>horas)
    {
      double pago;
      pago = tarifa*horas;
      cout<<left<< setw(18) <<seguroSocial<<setw(15)<<nombre<<setw(18)<<pago<<endl;  
    }
}

//para mostrar una interfaz y ejecutar el numera a) o b) 
void pregunta() 
{
  int n;
  cout<<"----------------------------------------------"<<endl;
  cout<<"¿Qué desea hacer?"<<endl;
  cout<<"Ingrese 1 para ingresar en la nomina"<<endl;
  cout<<"Ingrese 2 para mostrar los pagos a realizar, recuerde que archivo no existe no se mostrara ningun pago"<<endl;
  //cout<<"Ingrese 0 para finalizar el programa"<<endl;
  cout<<"----------------------------------------------"<<endl;
  cin>>n;
  cout<<"----------------------------------------------"<<endl;
  
  if (n==1){ingreso();}//para ejecutar a 
  else if (n==2){mostrarDatosIngresados();} //para ejecutar b 
}

int main()
{ 
  pregunta();
  return 0; 
}
