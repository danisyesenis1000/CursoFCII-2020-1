
class Circular
{
 public:
  Circular(double,double,double,double,int,double);
  ~Circular();
  double xpos( double);
  double ypos( double);
  
  
  double R;
  double w;
  double dt;
  double t;
  int n;
  double alpha;
  
  
};

class Espiral : public Circular
{
 public:
  Espiral(double,double,double,double,double,double,int,double);
  ~Espiral();
  double Mov_z(double, double,double);
  void Mostrar();
  
  double z0;
  double vz;
};
