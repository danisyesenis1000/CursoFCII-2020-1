#include<clases.h>


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
