/*9.3-8 b. Incluya la definición de clase creada para el ejercicio 8a en
un programa en C++ funcional que le pida al usuario que introduzca datos 
para tres empleados y despliegue los datos introducidos.*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//declaración de clase
class Empleado{
	private:
	  //atributos o características
	  int iiiiiidden; //número de identificacíon
	  float tasa;//tasa salarial en punto flotante
	  int homa; //número máximo de horas que debe trabajar a la semana
	  
	public:
	  Empleado(int=105083462, float=42.3, int=65);//metodo de tipo constructor 
	  //métodos o servicios
	  void intdat(int, float, int);//capacidad para introducir datos
	  void camdat(); //capacidad para cambiar datos
	  
	  void desdat();//desplegar datos existentes  
	  
	  void tit();//este es un setvicio para hacer un título general para el despliegue de datos 
	  void inu();//este objeto sirve para introducir datos 	  
  };
  
  Empleado::Empleado(int iiiiiiiden, float ttasa, int hhoma){//inicialización del constructor o atributos de la clase 
	  iiiiiidden=iiiiiiiden;
	  tasa=ttasa;
	  homa=hhoma;
  }
  
  void Empleado::intdat(int iiiiiiiden, float ttasa, int hhoma){//para introducir  datos aparte 
	  iiiiiidden=iiiiiiiden;
	  tasa=ttasa;
	  homa=hhoma;
	  return;
  }	
  
  void Empleado::camdat(){//para cambiar datos 
	  
	  string  sin;
	  string no="n";
	  string si="s";
	  cout<<"Si quiere puede cambiar los siguientes datos donde: "<<endl;
	  cout<<"El número de identificación es: "<<iiiiiidden<<endl;
	  cout<<"La tasa salarial es: "<<tasa<<endl;
	  cout<<"La cantidad máxima de horas permitidas son: "<<homa<<endl;
	  cout<<"Si no esta de acuerdo con estos datos, los puede cambiar marcando n, "<<endl;
	  cout<<"pero si esta de acuerdo con ellos marque s para mantenerlos igual "<<endl;
	  getline(cin, sin);
	  if (sin ==no){
		  cout<<"Como no esta de acuerdo con los datos primero introduzca el numero de identificacion"<<endl;
		  cin>>iiiiiidden;
		  cout<<"Ahora introduzca la tasa salarial"<<endl;
		  cin>>tasa;
		  cout<<"Ahora la cantidad de horas máximas trabajadas "<<endl;
		  cin>>homa;
	  }
	  else if (sin==si ){
		  cout<<"Todos los datos anteriores estan bien y así se mantendran "<<endl;
	  }
	  iiiiiidden=iiiiiidden;
	  tasa=tasa;
	  homa=homa;	
	  cout<<""<<endl;
	  cout<<""<<endl;
	  
	  return;
  }
  void Empleado::tit(){//Titulo del despliegue de datos
	  cout<<setw(64)<<"Los datos de los empleados que se tienen hasta el momento"<<endl;
	  cout<<"  "<<endl;
	  cout<<"Numero de identificación"<<setw(17)<<"Tasa salarial"
	      <<setw(29)<<"Horas maximas de trabajo"<<endl;
	  
  }
	    
	  
  
  void Empleado::desdat(){//para desplegar datos existentes
	  
	  cout<<setw(17)<<iiiiiidden<<setw(20)<<tasa<<setw(23)<<homa<<endl;
	  return;
  }
  
  void Empleado::inu(){//para introducir datos 
	  cout<<"por favor introdusca el mumero de indentidad"<<endl;
	  cin>>iiiiiidden;
	  cout<<"por favor introdusca la tasa salarial"<<endl;
	  cin>>tasa;
	  cout<<"por favor introdusca slas horas de maximas laborales permitidas a la semana"<<endl;
	  cin>>homa;
	  
	  return;
  }
	  
  
  
  int main(){
	  Empleado  f, e, a, b, c, d, g, h, i; //declaración de objetos
	  a.intdat(1040733261, 45.5, 64);//aplicación de entrada de datos al objeto a
	  b.intdat(340578709, 32.6, 60); //aplicación de entrada de datos al objeto b
	  c.intdat(219790943, 52.0, 59);//aplicación de entrada de datos al objeto c
	  d.intdat(234378983, 49.9, 61);//aplicación de entrada de datos al objeto d
	  g.inu();//asocial la clase de introducción de elementos al objeto g
	  h.inu();//asocial la clase de introducción de elementos al objeto h 
	  i.inu();//asocial la clase de introducción de elementos al objeto i
	  e.camdat();//aplicación de cambio de datos al objeto e
	  a.camdat();//aplicación de cambio de datos al objeto a
	  b.camdat();//aplicación de cambio de datos al objeto b
	  c.camdat();//aplicación de cambio de datos al objeto c
	  d.camdat();//aplicación de cambio de datos al objeto d
	  g.camdat();//aplicación de cambio de datos al objeto g
	  h.camdat();//aplicación de cambio de datos al objeto h
	  i.camdat();//aplicación de cambio de datos al objeto i
	  f.tit();//aquí se aplica el título para desplegar la lista de datos
	  e.desdat();//aplicación de despliegue de datos en el objeto e
	  a.desdat();//aplicación de despliegue de datos en el objeto
	  b.desdat();//aplicación de despliegue de datos en el objeto
	  c.desdat();//aplicación de despliegue de datos en el objeto
	  d.desdat();//aplicación de despliegue de datos en el objeto
	  g.desdat();//aplicación de despliegue de datos en el objeto
	  h.desdat();//aplicación de despliegue de datos en el objeto
	  i.desdat();//aplicación de despliegue de datos en el objeto
	  
	  return 0;
  }
