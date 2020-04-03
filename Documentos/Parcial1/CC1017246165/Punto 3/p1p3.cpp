#include<iostream>
#include<cmath>
#include<iomanip>


using namespace std;

//Numeros complejos con clase

class complejo{
private:
  double ParteReal1,ParteImaginaria1,ParteReal2,ParteImaginaria2;
public:
  complejo(double,double,double,double); //Constructor
  void AsignarDatos(double,double,double,double);
  double SumaComplejos1();
  double SumaComplejos2(); 
  double RestaComplejos1();
  double RestaComplejos2();
  double FormaCompleja();
  void ObtenerParteReal();
  void ObtenerParteImaginaria();
};

complejo::complejo(double real1,double imaginario1,double real2, double imaginario2){
  ParteReal1=real1;
  ParteImaginaria1=imaginario1;
  ParteReal2=real2;
  ParteImaginaria2=imaginario2;
}

void complejo::AsignarDatos(double real21,double imaginario21,double real22,double imaginario22){
  ParteReal1=real21;
  ParteReal2=real22;
  ParteImaginaria1=imaginario21;
  ParteImaginaria2=imaginario22;
}

double complejo::SumaComplejos1(){
  double sumari;
  sumari=ParteReal1+ParteReal2;
  return sumari;
}

double complejo::SumaComplejos2(){
  double sumai;;
  sumai=ParteImaginaria1+ParteImaginaria2;
  return sumai;
}

double complejo::RestaComplejos1(){
  double restar;
  restar=ParteReal1-ParteReal2;
  return restar;
}

double complejo::RestaComplejos2(){
  double restai;
  restai=ParteImaginaria1-ParteImaginaria2;
  return restai;
}
double complejo::FormaCompleja(){
  double fr1,fr2,fi1,fi2;
  fr1=ParteReal1;
  fr2=ParteReal2;
  fi1=ParteImaginaria1;
  fi2=ParteImaginaria2;
  cout<<"El primer número complejo en la forma a+bi es: "<<fr1<<" + "<<fi1<<"i"<<endl;
  cout<<"El segundo número complejo en la forma a+bi es: "<<fr2<<" + "<<fi2<<"i"<<endl;
}


void complejo::ObtenerParteReal(){
  cout<<"La parte real del primer número es: "<<ParteReal1<<endl;
  cout<<"La parte real del segundo número es: "<<ParteReal2<<endl;
  cout<<"La parte real de la suma es: "<<SumaComplejos1()<<endl;
  cout<<"La parte real de la resta es: "<<RestaComplejos1()<<endl;
}

void complejo::ObtenerParteImaginaria(){
  cout<<"La parte imaginaria del primer número es: "<<ParteImaginaria1<<endl;
  cout<<"La parte imaginaria del segundo número es: "<<ParteImaginaria2<<endl;
  cout<<"la parte imaginaria de la suma es: "<<SumaComplejos2()<<endl;
  cout<<"la parte imaginaria de la resta es: "<<RestaComplejos2()<<endl;
}

int main(){
  double ireal1,ireal2,iimag1,iimag2;
  cout<<"Ingrese la parte real del primer numero complejo: ";
  cin>>ireal1;
  cout<<"Ingrese la parte imaginaria del primer numero complejo : ";
  cin>>iimag1;
  cout<<"Ingrese la parte real del segundo numero complejo : ";
  cin>>ireal2;
  cout<<"Ingrese la parte imaginaria del segundo numero complejo : ";
  cin>>iimag2;

  cout<< "A continuación los operaciones:"<<endl;
  complejo com(ireal1,iimag1,ireal2,iimag2);
  com.FormaCompleja();
  com.ObtenerParteReal();
  com.ObtenerParteImaginaria();
  
  cout<< "Ahora para dos numeros fijos:"<<endl;
  double rreal1,rreal2,rimag1,rimag2;
  rreal1=13;
  rimag1=8;
  rreal2=5;
  rimag2=3;
  complejo com1(rreal1,rimag1,rreal2,rimag2);
  com1.FormaCompleja();
  com1.ObtenerParteReal();
  com1.ObtenerParteImaginaria();
  
  return 0;
}
