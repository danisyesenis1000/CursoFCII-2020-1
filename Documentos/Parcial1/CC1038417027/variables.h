

class imag
{
 private:
  double parteImaginaria,parteReal;
  
 public:
  imag(double,double);
  void asignarDatos(double,double);
  double obtenerParteReal();
  double obtenerParteImaginaria();
  void sumaNumerosComplejos(double,double);
  void restaNumerosComplejos(double,double);
  void mostrarNumeroComplejo();
};
