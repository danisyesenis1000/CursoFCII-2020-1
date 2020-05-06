//Diseñamos una clase llamada Circular que se encarga de sacar la posicion en y y la posicion en x
/*Ademas elaboramos una clase derivada llamada Espiral que hereda las variables y metodos de la clase Circular y añadimos un nuevo metodo el cual es la posicion en z*/

//declaracion de la clase

class Circular //clase base
{
 protected: //miembros de datos
  float R;
  float w;
  float dt;
  float Total;
  float Numsdt;
  float fase;
  
 public: //miembros de funciones
  
  Circular(float=0.0,float=0.0,float=0.0,float=0.0,int=0,float=0.0);
  void xpos(float [],int);
  void ypos(float [],int);
  ~Circular(); 
};

class Espiral : public Circular //clase derivada
{
protected: //miembros de datos
  float zo;
  float vz;
public: //miembros de funciones
  Espiral(float=0.0,float=0.0,float=0.0,float=0.0,int=0.0,float=0.0,float=0.0, float=0.0);
  void zpos(float [],int);
  ~Espiral();
};
