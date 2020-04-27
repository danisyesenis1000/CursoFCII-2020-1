/*Se crearon dos formas de de clases, donde se crea la lista desde la clase y donde se crea una función que genera la lista a partir de la clase, ambas arrojan
El mismo resultado y se hizo con el fin de examinar su utilidad, más allá de cual fuera la más acertada o si había una más acertada que otra para los fines
del ejercicio
 */

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

//Clase circular y ecuaciones de movimiento

class Circular{
private:
  double radio; //Radio del circulo
  double fangular; //Frecuencia angular
  double tinter; //Intervalos de tiempo
  double ttotal; //Tiempo total
  int ntiempos; //Numero de intervalos
  double fase; //Fase angular
public:
  Circular(double,double,double,double,int,double); //Constructor
  ~Circular(); //Destructor
  void Datos();
  double xpos1(); //Funcion miembro eje x
  double ypos1(); //Funcion miembro eje y
  double xpos2(); //Función miembro eje x
  double ypos2(); //Función miembro eje y
};

class Espiral : public Circular{
private:
  double tinterch;
  double ttotalch;
  int ntiemposch; //Se podría definir esto público en un inicio y así heredarlo también, pero el ejercicio solo pide heredar el movimiento como tal y no sus datos, también se puede declarar protected y así manipularla desde la clase estos datos que se usan compartidamente, pero nada me indico que esto se pretendía en el ejercicio más allá de mostrar que la clase espiral hereda el movimiento circular como tal y lo puede expresar a través de ella. 
  double posin;
  double velin;
public:
  Espiral(double,double,double,double,int,double,double,double);
  ~Espiral();
  void Datosz();
  double zpos1();
  double zpos2();
};

//Constructor

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

Espiral::Espiral(double radio1,double fangular1,double tinter1,double ttotal1, int ntiempos1,double fase1,double posin1,double velin1) : Circular(radio1,fangular1,tinter1,ttotal1,ntiempos1,fase1){
  
  posin = posin1;
  velin = velin1;
  tinterch= tinter1;
  ttotalch=ttotal1;
  ntiemposch=ntiempos1;
}

Espiral::~Espiral(){
}

void Circular::Datos(){
  cout<<"El radio del cuerpo en el circulo es: "<< radio <<endl;
  cout<<"La frecuencia angular es: "<< fangular <<endl;
  cout<<"El intervalo temporal seleccionado es de: "<< tinter <<endl;
  cout<<"El tiempo total del movimiento es: "<< ttotal <<endl;
  cout<<"El numero de intervalos dado es: "<< ntiempos <<endl;
  cout<<"La fase asignada fue: "<< fase <<endl;
}

void Espiral::Datosz(){
  Datos();
  cout<<"La posición inicial en el eje z es: "<<posin<<endl;
  cout<<"la velocidad inicial en el eje z es: "<<velin<<endl;
}

//Primera manera, la lista se hace desde las funciones miembros


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

double Espiral::zpos1(){
  xpos1(); //Hereda de la clase madre en la implementación
  ypos1();
  double zpl[ntiemposch]; 
  for(int i=0;i<=ntiemposch;i++){
    zpl[i]=posin+velin*tinterch*i;
    cout<<"La posicion en z para el tiempo t="<<i*tinterch<< "s es: "<<zpl[i] <<endl;
  }
}

//Segunda manera, se hace la función miembro y se juega con las variables para después crear una función que haga la lista
  
  
//Funcion miembro que indica el ejercicio tal cual
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

double Espiral::zpos2(){
  double zpl;
  zpl=posin+velin*tinterch;
  return zpl;
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

double listaz(double R,double FA,double IT,double TT,int NT,double F,double P,double V){
  for(int i=0;i<=NT;i++){
    double ITL=i*IT;
    Espiral espira(R,FA,ITL,TT,NT,F,P,V);
    cout<<"La posición en x para el tiempo t="<<ITL<< "s es: " <<espira.xpos2() <<endl; //La herencia cae sobre la función
    cout<<"La posición en y para el tiempo t="<<ITL<< "s es: " <<espira.ypos2() <<endl;
    cout<<"La posición en z para el tiempo t="<<ITL<< "s es: " <<espira.zpos2() <<endl;
  } 
}  


//Y el cuerpo donde evaluamos la viabilidad de ambos métodos

int main(){
  int elect;
  double r1,fa1,it1,tt1,nt1,f1,p1,v1;
  r1=4;
  fa1=1.3;
  it1=1;
  tt1=6;
  nt1=tt1/it1; //Calcula la cantidad de intervalos
  f1=0.78;
  p1=0.5;
  v1=2.2;
  double r2,fa2,it2,tt2,nt2,f2,p2,v2;
  cout <<"Si desea usar los datos suministrados por el programa digite el numero '1', si los desea ingresar manualmente digite cualquier otro número natural"<<endl;
  cin >>elect;
  if(elect==1){ //Se usa de acuerdo a los datos dados por el programa
    //Circular circulo1(r1,fa1,it1,tt1,nt1,f1); Muestra los datos que está usando el programa por defecto
    Espiral espira1(r1,fa1,it1,tt1,nt1,f1,p1,v1);
    //circulo1.Datos();
    espira1.Datosz();
    //circulo1.xpos1();
    //circulo1.ypos1();
    espira1.zpos1();
    //listax(r1,fa1,it1,tt1,nt1,f1);
    //listay(r1,fa1,it1,tt1,nt1,f1);
    listaz(r1,fa1,it1,tt1,nt1,f1,p1,v1);
  }
  else{ //Se usa si el usuario desea ingresar los datos 
    cout <<"Ingrese el valor del radio"<<endl;
    cin>>r2;
    cout <<"Ingrese el valor de frecuencia angular"<<endl;
    cin>>fa2;
    cout <<"Ingrese el intervalo de tiempo"<<endl;
    cin>>it2;
    cout <<"Ingrese el tiempo total de movimiento"<<endl;
    cin>>tt2;
    nt2=tt2/it2; //Calcula la cantidad de intervalos
    cout <<"Asigne la fase correspondiente"<<endl;
    cin>>f2;
    cout <<"Ingrese la posición inicial: "<<endl;
    cin>>p2;
    cout <<"Ingrese la velocidad inicial: "<<endl;
    cin>>v2;
    //Circular circulo2(r2,fa2,it2,tt2,nt2,f2);
    Espiral espira2(r2,fa2,it2,tt2,nt2,f2,p2,v2);
    //circulo2.Datos();
    espira2.Datosz();
    //circulo2.xpos1();
    //circulo2.ypos1();
    espira2.zpos1();
    //listax(r2,fa2,it2,tt2,nt2,f2);
    //listay(r2,fa2,it2,tt2,nt2,f2);
    listaz(r2,fa2,it2,tt2,nt2,f2,p2,v2);
  }
  
  return 0;
}
