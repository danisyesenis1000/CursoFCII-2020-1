// Definimos la clase complejo.

class Complejo
{
 public:
  Complejo(double,double,double,double);           // Constructor
  void AsignarDatos(double,double,double,double);  // Le asigno 4 datos porque son 2 numeros complejos
  void AsignarParteReal(double,double);            // de los dos numeros complejos hay dos partes reales
  void AsignarParteImaginaria(double,double);      // de los dos numeros complejos hay dos partes imaginarias
  double ObtenerParteReal();
  double ObtenerParteImaginaria();
  double SumaReal();                              // Suma las partes reales
  double SumaImaginaria();                        // Suma las partes imaginarias
  double RestaReal();                             // Resta las partes reales
  double RestaImaginaria();                       // Resta las partes imaginarias
  void MostrarNumero1();                          // Muestra el primer numero de la forma a+ib
  void MostrarNumero2();                          // Mustra el segundo numero de la forma c+id
  void MostrarDatos();                            // Muestra todos los datos.


 private:
  double ParteReal1;               // Defino las variables de los dos numeros complejos que se van a utilizar
  double ParteImaginaria1;
  double ParteReal2;
  double ParteImaginaria2;
};
