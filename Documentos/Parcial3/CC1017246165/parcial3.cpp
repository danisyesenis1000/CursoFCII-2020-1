//Parcial de:
//Santiago Andrés Pérez
//Bryan Pérez
//Juan José Ochoa 

#include<iostream>
#include<iomanip>
#include<cmath>
#include <fstream>
#include <cstdlib>

using namespace std;

class Hiperbolicas{ //Clase que nos resuelve la ecuación hiperbólica
private:
  double h,k,lambda; //Densidad de pasos
  double LongitudFinal; //Longitud a recorrer
  double TiempoMaximo; //Tiempo total 
  double ConstanteEq; //Constante que caracteriza la función de onda
public:
  const static int m=10; //Será de nuevo tomada en el main, por esto se pone public 
  const static int N=20;
  double Funcionf[m+1]; //Funcion que define condicion de frontera
  double Funciong[m+1]; //Funcion que define condicion de frontera
  Hiperbolicas(double,double,double,const double[m+1],const double[m+1]); //Constructor
  ~Hiperbolicas(); //Destructor
  double Sequaciones(); 
  
  
};

Hiperbolicas::Hiperbolicas(double LongitudFinal1,double TiempoMaximo1, double ConstanteEq1,const double Funcionf1[m+1],const double Funciong1[m+1]){
  LongitudFinal=LongitudFinal1;
  TiempoMaximo=TiempoMaximo1;
  ConstanteEq=ConstanteEq1;
  h=LongitudFinal/m;
  k=TiempoMaximo/N;
  lambda=(k*ConstanteEq)/h;
  for(int i=0;i<=m;i++){ //Arreglo de la función 1
    Funcionf[i]=Funcionf1[i];
  }
  for(int i=0;i<=m;i++){ //Arreglo de la función 2
    Funciong[i]=Funciong1[i];
  }
}

Hiperbolicas::~Hiperbolicas(){
}

double Hiperbolicas::Sequaciones(){
  double Matriz[m+1][N+1];
    
  string archivoseg = "datos.dat";
  ofstream archivo_datos;
  archivo_datos.open(archivoseg.c_str());
  if (archivo_datos.fail()){
    cout <<"El archivo no se abrió exitosamente"<<endl;
    exit(1);
  }
   //Formato de los datos
  archivo_datos << setiosflags(ios::fixed);
        

  Matriz[0][0]=Funcionf[0]; //Condición de frontera
  Matriz[m][0]=Funcionf[m]; //Condición de frontera
  for(int i=1;i<=m;i++){
    Matriz[i][0]=Funcionf[i];
    Matriz[i][1]=(1-lambda*lambda)*Funcionf[i]+((lambda*lambda)/2)*Funcionf[i+1]+((lambda*lambda)/2)*Funcionf[i-1]+k*Funciong[i];
  //Es necesario definir todos estos valores primero para poder dar las condiciones iniciales mejoradas, si se empieza a definir en la multiplicación, desborda la matriz por la necesidad de [i][j]
  }
  for(int j=1;j<N;j++){
    Matriz[0][j]=0; //Condición inicial
    Matriz[m][j]=0; //Condicion incial
    Matriz[m][N]=0; //Se define desde aquí para no desbordar la matriz
    for(int i=1;i<m;i++){
      Matriz[i][j+1]=2*(1-lambda*lambda)*Matriz[i][j]+(lambda*lambda)*(Matriz[i+1][j]+Matriz[i-1][j])-Matriz[i][j-1]; //Multiplicacion Matriz
    }
    // Acá hay que tener especial cuidado con la multiplicación de matrices, observemos que primero se toma el índice j y después el i, esto por como se soluciona para cada tiempo, todas las posiciones y así además se evitan desbordamientos del [i+1]
  }
  for(int i=0;i<=m;i++){
    archivo_datos<<"x= "<<setprecision(3)<<setiosflags(ios::showpoint)<<i*h;
    for(int j=0;j<=N;j++){
      archivo_datos<<setw(9)<<setprecision(3)<<setiosflags(ios::showpoint)<<Matriz[i][j]; //Imprime
    }
    archivo_datos<<"\n";
  }
  archivo_datos.close();
}


int main(){
  const double PI=3.141592653589793238463;
  double lf,Tf,Cte;
  lf=1;
  Tf=1;
  Cte=2;
  double f[Hiperbolicas::m+1];
  double g[Hiperbolicas::m+1]={0};
  double x[Hiperbolicas::m+1];
  double M[Hiperbolicas::m+1][Hiperbolicas::N+1];
  
  //Creacion y verificación de éxito en la creación del archivo
  

  for(int i=0;i<=Hiperbolicas::m;i++){
    x[i]=(lf*i)/(Hiperbolicas::m);
    f[i]=sin(PI*x[i]);
  }
  Hiperbolicas hiper1(lf,Tf,Cte,f,g);
  hiper1.Sequaciones();

  return 0;
} 
