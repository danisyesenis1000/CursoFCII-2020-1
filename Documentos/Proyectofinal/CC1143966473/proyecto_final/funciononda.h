/*==============ECUACIÓN DE SCHRODINGER DEPENDIENTE DEL TIEMPO=================*/

class FuncionOnda // clase Schrodinger
{
 private:
    double a;       //ancho de barrera de potencial
    double V0;      //altura de barrera de potencial
    double x0;      //posicion inicial para el paquete de ondas
    double sig;     //ancho de paquete
    double k0;      //numero de onda promedio
    double xmax;    //maximo x
    double hx;      //tamaño de paso espacial
    double tmax;    //tiempo maximo de propagacion
    double ht;      //paso temporal
    int nout;       //salida cada nout pasos
    int nx;         //numero de intervalos en x
    int nt;         // numero de intervalos en t
    int nx2;
   
 public:
  FuncionOnda(double =0,double =0, double =0, double =0,double =0,double =0,double =0, double =0, double =0, int =0, int=0,int =0, int =0);  //constructor
  double Potencial(double ,double ,double);                         //prototipo de la funcion potencial
  void Paqueteinicial(double [], double [], double [], int, double, double, double); //prototipo de la funcion paquete de onda inicial
  void Densidadprob(double [], double [], double [], int , double , double&); //prototipo de la funcion densidad de probabilidad
  double* Init_arrreglo(int, int);  // funcion para llenar arreglo con indices
  void SolGaussSeidel(double [], double [], double [], int , double ,double ); // protito meotodo gaus Seidel
  
  ~FuncionOnda(); //destructor
};



