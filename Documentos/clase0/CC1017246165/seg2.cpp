#include<iostream>
#include<iomanip>
//include<string>
using namespace std;

//Construyamos nuestra clase

class Rectangulo{
private:           //Datos miembro
  double largo,ancho;
public:            //Funciones miembro
  Rectangulo(double,double); //Constructor
  void AsignarDatos(double,double);
  void AsignarLargo(double);
  void AsignarAncho(double);
  double Area();
  double Perimetro();
  void MostrarDatos();
  void ObtenerAncho();
  void ObtenerLargo();
};

//Es "quien" usará las funciones

Rectangulo::Rectangulo(double Largo1,double Ancho1){
  largo = Largo1;
  ancho = Ancho1;
  
}

void Rectangulo::AsignarDatos(double Largo2,double Ancho2){
  largo=Largo2;
  ancho=Ancho2;
}
void Rectangulo::AsignarLargo(double Largo2){
  largo=Largo2;
}
void Rectangulo::AsignarAncho(double Ancho2){
  ancho=Ancho2;
}

double Rectangulo::Area(){
  double area1;
  area1 = largo*ancho;
  return area1;
}

double Rectangulo::Perimetro(){
  double perimetro1;
  perimetro1= (largo*2)+(ancho*2);
  return perimetro1;
}

void Rectangulo::MostrarDatos(){
  cout <<"Se mostraran los datos y calculos del rectangulo: "<< endl;
  cout <<"largo     Ancho     Area     Perimetro\n";
  cout <<"_____     _____     _____     _________ \n";
  cout << setw(4)<< setiosflags(ios::showpoint)<< largo;
  cout << setw(9)<< ancho;
  cout<< setw(11)<< Area();
  cout<< setw(12)<< Perimetro()<<endl;
}
void Rectangulo::ObtenerLargo(){
  cout <<"El largo es: "<< largo<<endl;
  }
void Rectangulo::ObtenerAncho(){
  cout <<"El ancho es: " <<  ancho<<endl;
}



int main(){
  double largo3,ancho3,largo4,ancho4;
  cout<< "Ingrese el largo del rectángulo: ";
  cin>> largo3;
  cout<< "Ingrese el ancho del rectángulo: ";
  cin>> ancho3;
  
  Rectangulo r(largo3,ancho3);
  r.ObtenerLargo();
  r.ObtenerAncho();
  r.MostrarDatos();

  cout<< "A continuación un calculo con datos fijos: "<<endl;
  
  largo4=3;
  ancho4=5;
  Rectangulo r1(largo4,ancho4);
  r1.ObtenerLargo();
  r1.ObtenerAncho();
  r1.MostrarDatos();
  
return 0;
  }
