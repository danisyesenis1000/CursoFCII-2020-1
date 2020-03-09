/*Tarea2
  Diseñar una clase llamada Rectangulo que tenga como datos miembro en doble precision largo y ancho y las funciones miembro de asignarDatos, asignarAncho, asignarLargo, area, perimetro, mostrarDatos, obtenerAncho y obtenerLargo.*/

//Esta es la seccion de declarar la clase

class Rectangulo

{
  
private:
  
  double largo; //miembros de datos
  double ancho;
  
public: //miembros de funciones
  
  Rectangulo(int =0, int =0); //constructor de la clase
  void asignarDatos(int, int);//prototipo de funcion
  void asignarAncho(int); //prototipo de funcion
  void asignarLargo(int); //prototipo de funcion
  void area(); //prototipo de funcion
  void perimetro(); //prototipo de funcion
  void mostrarDatos(); //prototipo de funcion
  void obtenerAncho(); //prototipo de funcion
  void obtenerLargo(); //prototipo de funcion
  
};
