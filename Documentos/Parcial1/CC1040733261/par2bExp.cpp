/*b) Ahora diseñe la clase "Expiral", que sera derivada de la clase Circular, para que herede el
movimiento circular y adicione el movimiento en la direcion del eje z, de acuerdo con la
ecuacion:
z = z0 + vz ∗ t*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
double t=0, x, y, z;
const double pi=3.141519;

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
  
  //seccion de implementacion de clase padre 
    //constructor de la clase padre 
  Circular::Circular(double Rii, double Wii, double Dtt, double Ttt, double aa){//inicialización del constructor o atributos de la clase
	  Ri=Rii;
	  Wi=Wii;
	  Dt=Dtt;
	  Tt=Ttt;
	  a=aa;
  }
  Circular::~Circular(){//Inicialización del Destructor
  }
  
  
  void Circular::intdat(double Rii, double Wii, double Dtt, double Ttt, double aa){//para introducir los datos aparte, esto sera una función base
	  Ri=Rii;
	  Wi=Wii;
	  Dt=Dtt;
	  Tt=Ttt;
	  a=aa;
	  return;
  }
  
  void Circular::xpos(){//Función para la posición de x
	  	  
	  x=Ri*cos((t*Wi)+a);
	  return;
  }
  
  void Circular::ypos(){//Función para la posición de y	  
	  y=Ri*sin((t*Wi)+a);
	  return ;
  }
   
  void Circular::movcir(){//funcion que entrega los puntos xy del movimiento circular en el transcurso de tiempo 
	  cout<<setw(64)<<"Rara el movimiento circular con características :"<<endl;
	  cout<<setw(15)<<"Radio: "<<Ri<<setw(25)<<"Freecuencia angular: "<<Wi<<setw(18)<<"Face angular: "<<a<<endl;
	  cout<<setw(30)<<"Intervalo temporal: "<<Dt<<setw(31)<<"Tiempo total de movimiento "<<Tt<<endl; 
	  for(t=0; t<Tt; t=t+Dt){
		  xpos();  
		  ypos();
		  cout<<"En el tiempo:"<<setw(4)<<t<<setw(22)<<"La posición x es:"<<setw(11)<<x<<setw(22)<<"La posición y es:"<<setw(11)<<y<<endl;
	}
	cout<<""<<endl;
	cout<<""<<endl;
	return ;
}

 //Declaración de clase para la clase derivada
 //Expiral que se deriva de circular
class Expiral:public Circular{
	protected:
	  double Zin;//agrega un miempro de datos adicional que es la distancia recorrida en el eje z
	  double Vzin;//agrega otro miembro de datos adicionales que es la velocidad inicial que recorre en el eje z
	  
	public:
	  Expiral(double=1.5, double=2.0, double=0.1, double=3.2, double=pi/2, double=0.1, double=2.1); //Método del tipo constructor para la clase hija expiral
	  void intdatt(double, double, double, double, double, double, double);//capacidad para introducir datos para la clase hija
	  
	  void zpos();
	  void mov();	  
};
//Sección de implementación para la clase hija  Expiral
  //constructor de la clase hija expiral
Expiral::Expiral(double Rii, double Wii, double Dtt, double Ttt, double aa, double zin, double vzin):Circular(Rii, Wii, Dtt, Ttt, aa){//
	Zin=zin;
	Vzin=vzin;
}

//introducir datos aparte para la clase hija 
void Expiral::intdatt(double Rii, double Wii, double Dtt, double Ttt, double aa, double zin, double vzin){
    Ri=Rii;
    Wi=Wii;
    Dt=Dtt;
    Tt=Ttt;
    a=aa;
	Zin=zin;
	Vzin=vzin;
	return;	
}
void Expiral::zpos(){//Función para la posición de z
	z=Zin+(Vzin*t);
	return;
}

void Expiral::mov(){//funcion que entrega los puntos xyz del movimiento de la clse hija en el transcurso de tiempo 
	cout<<setw(64)<<"Rara el movimiento circular con características :"<<endl;
	cout<<setw(36)<<"Posición inicial en z: "<<Zin<<setw(27)<<"Velocidad inicial en z: "<<Vzin<<endl;
	cout<<setw(15)<<"Radio: "<<Ri<<setw(25)<<"Freecuencia angular: "<<Wi<<setw(18)<<"Face angular: "<<a<<endl;
	cout<<setw(30)<<"Intervalo temporal: "<<Dt<<setw(31)<<"Tiempo total de movimiento "<<Tt<<endl; 
	
	for(t=0; t<Tt; t=t+Dt){
		  xpos();  
		  ypos();
		  zpos();
		  cout<<"En tiem:"<<setw(4)<<t<<setw(10)<<"pos x:"<<setw(10)<<x<<setw(10)<<"pos y:"<<setw(11)<<y<<setw(10)<<"pos z:"<<setw(11)<<z<<endl;
	  }
	  cout<<""<<endl;
	  cout<<""<<endl;
	return;	
}	

int main(){
	  Circular a, b;//declaración de objetos para el movimiento circular
	  Expiral c, d;//declaración de objetos para el movimiento Expiral
	  a.movcir();//aplicación del movimiento circular al objeto a
	  a.~Circular();//aplicación del destructor al objeto a
	  b.intdat(2, 3, 0.5, 10, pi/6);//aplicación de entrada de datos al objeto b
	  b.movcir();//aplicación del movimiento circular al objeto b
	  b.~Circular();//aplicación del destructor al objeto b
	  c.mov();//aplicación del movimiento expiral al objeto c
	  d.intdatt(1.9, 4, 0.4, 20, pi/8, 1, 3);//aplicación de entrada de datos al objeto d
	  d.mov();//aplicación del movimiento expiral al objeto d
	  
	  return 0;
}
