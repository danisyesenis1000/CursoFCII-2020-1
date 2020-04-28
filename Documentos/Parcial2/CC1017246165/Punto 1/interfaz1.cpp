#include"clases1.h"

using namespace std;

Circular::Circular(double radio1,double fangular1,double tinter1,double ttotal1, int ntiempos1,double fase1){
  radio = radio1;
  fangular = fangular1;
  tinter = tinter1;
  ttotal = ttotal1;
  ntiempos = ntiempos1;
  fase = fase1;
}

//Destructor

Circular::~Circular(){
}

void Circular::Datosxy(){
  cout<<"El radio del cuerpo en el circulo es: "<< radio <<endl;
  cout<<"La frecuencia angular es: "<< fangular <<endl;
  cout<<"El intervalo temporal seleccionado es de: "<< tinter <<endl;
  cout<<"El tiempo total del movimiento es: "<< ttotal <<endl;
  cout<<"El numero de intervalos dado es: "<< ntiempos <<endl;
  cout<<"La fase asignada fue: "<< fase <<endl;
}

double Circular::xpos1(){
  double xpl[ntiempos];
  for(int i=0;i<=ntiempos;i++){
    xpl[i]=radio*cos(fangular*tinter*i+fase);
    cout<<"La posición en x para el tiempo t="<<i*tinter<< "s es: " <<xpl[i] <<endl;
  }
}

double Circular::ypos1(){
  double ypl[ntiempos]; //Se crea la lista del tamaño de la cantidad de intérvalos
  for(int i=0;i<=ntiempos;i++){
    ypl[i]=radio*sin(fangular*tinter*i+fase); //Cada parte de la lista depende de i
    cout<<"La posición en y para el tiempo t="<<i*tinter<< "s es: " <<ypl[i] <<endl; //Se imprime
  }
}
double Circular::xpos2(){
  double xpl;
  xpl=radio*cos(fangular*tinter+fase);
  return xpl;
}

//Funcion miembro que indica el ejercicio tal cual
double Circular::ypos2(){
  double ypl;
  ypl=radio*sin(fangular*tinter+fase);
  return ypl;
}


double listax(double R,double FA,double IT,double TT,int NT,double F){
  for(int i=0;i<=NT;i++){
    double ITL=i*IT; //Se define esta variable que terminara creando las distintas posiciones pues depende de i que a su vez depende de los tiempos
    Circular circulo(R,FA,ITL,TT,NT,F); //Se llama la clase
    cout<<"La posición en x para el tiempo t="<<ITL<< "s es: " <<circulo.xpos2() <<endl; //Se hace uso de lo que finalmente terminará creando la lista
  } 
}
 

double listay(double R,double FA,double IT,double TT,int NT,double F){
  for(int i=0;i<=NT;i++){
    double ITL=i*IT;
    Circular circulo(R,FA,ITL,TT,NT,F);
    cout<<"La posición en y para el tiempo t="<<ITL<< "s es: " <<circulo.ypos2() <<endl;
  } 
}

