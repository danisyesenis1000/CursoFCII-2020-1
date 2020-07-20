/*a) Diseñe una clase llamada "Circular" con los datos para el radio 
del circulo en el plano xy, la frecuencia angular de la particula que se
mueve en el circulo, un pequeño intervalo de tiempo, el tiempo total que 
durara el movimiento del cuerpo, el numero de intervalos de tiempo 
tenidos en cuenta y una fase. Tambien deben aparecer el constructor y 
el destructor de la clase, las funciones miembros "xpos" y "ypos" que 
calculan las posiciones xy dado el tiempo. Las siguientes son las ecuaciones que debe codificar para xpos y ypos:
xpos = Rcos(wt + α)
ypos = Rsin(wt + α)*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
double t=0, x, y;//variables generales 
const double pi=3.141519;//constante general 

//declaración de clase
class Circular{
	protected:
	  //atributos o características
	  double Ri; //radio del círculo
	  double Wi;//frecuencia angular de la partícula que se mueve en el círculo
	  double Dt;//intervalo de tiempo 
	  double Tt;//tiempo total 
	  double a; //face angular
	   
	public:
	  
	  Circular(double=1.5, double=2.0, double=0.1, double=3.2, double=pi/4.0);//metodo de tipo constructor 
	  ~Circular();//Destructor 
	  //métodos o servicios
	  void intdat(double, double, double, double, double);//capacidad para introducir datos
	  void xpos();//posicion en x
	  void ypos();//posicion en y
	  void movcir();//movimiento en el tiempo
  };
  
  //seccion de implementacion de clases 
  Circular::Circular(double Rii, double Wii, double Dtt, double Ttt, double aa){//inicialización del constructor o atributos de la clase
	  Ri=Rii;
	  Wi=Wii;
	  Dt=Dtt;
	  Tt=Ttt;
	  a=aa;
  }
  
  Circular::~Circular(){
  }
  void Circular::intdat(double Rii, double Wii, double Dtt, double Ttt, double aa){//para introducir los datos aparte
	  Ri=Rii;
	  Wi=Wii;
	  Dt=Dtt;
	  Tt=Ttt;
	  a=aa;
	  return;
  }
  
  void Circular::xpos(){
	  	  
	  x=Ri*cos((t*Wi)+a);
	  return;
  }
  
  void Circular::ypos(){	  
	  y=Ri*sin((t*Wi)+a);
	  return ;
  }
   
  void Circular::movcir(){
	  for(t=0; t<Tt; t=t+Dt){
		  xpos();  
		  ypos();
		  cout<<"En el tiempo:"<<setw(4)<<t<<setw(22)<<"La posición x es:"<<setw(11)<<x<<setw(22)<<"La posición y es:"<<setw(11)<<y<<endl;
	}
	
	cout<<"  "<<endl;
	return ;
}

int main(){
	  Circular a, b;
	  b.intdat(2, 3, 0.5, 10, pi/6);
	  b.movcir();
	  b.~Circular();
	  a.movcir();
	  a.~Circular();
	  
	  return 0;
}
	   
  
   
