//declaracion de la clase
class Parabolica // clase Parabolica
{
 private:
  float alpha; 
  float xfin; 
  float m; 
  float tfin; 
  float pasok; 
   
 public:
  Parabolica(double =0,double =0, double =0, double =0,double =0); //constructor
  double* Vector(int , int ); //funcion vector
  void TriDiagSys(double [], double [], double [], double [], int ); //funcion para solucionar
  void metdifpro(double [], double [], int , double , double ,double); //funcion para diferencias progresivas
  void metdifreg(double [], double [], int , double , double ,double); //funcion para diferencias regresivas
  void metcrankni(double [], double [], int , double , double , double ); //funcion para crank-nikolson
  ~Parabolica(); //destructor
};
