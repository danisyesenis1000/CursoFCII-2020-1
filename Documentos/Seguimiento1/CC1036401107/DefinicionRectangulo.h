
//Definimos la clase Rectangulo

class Rectangulo
{
 public:
  Rectangulo (double, double);
  void AsignarDatos(double, double);
  void AsignarLargo(double);
  void AsignarAncho(double);
  double Area();
  double Perimetro();
  void MostrarDatos();
  double ObtenerLargo();
  double ObtenerAncho();
  
 private:             
  double largo;
  double ancho;    
};
