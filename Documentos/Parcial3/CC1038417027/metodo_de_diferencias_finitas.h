

typedef double (*functype)(double *);

class metodo
{
 private:
  int N; //numero de particiones 
  double inicioX,finalX,inicioY,finalY; //intervalos de x y y 
  double h; //el valor de h no cambia entonces se define aca para que sea global para todos
  //double (*p1)(double);
  //double (*q1)(double);
  //double (*r1)(double);
  functype *func;
  
 public:
  metodo(int , double, double, double, double,functype *f);
  ~metodo();
  //metodo(int , double, double, double, double,double(*)(double),double(*)(double),double(*)(double)); //de ingresa N,a,b,alfa,betta
  //void establecerDatos(int, double,double,double,double,double(*);
  //void establecerDatos(int, double,double,double,double,double(*)(double),double(*)(double),double(*)(double)); //establece los valores de N,a,b,alfa,betta
  //double c(double(*)(double));
  void paso();
  
};
  
