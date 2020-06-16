class Reinas{
   public:

   static const int L=8;//Tamaño del tablero
   bool T[L][L];//Arreglo asociado al tablero

   Reinas();

   long mod(long a, long b);//Función modulo 
   void plot();//Grafica el tablero
   bool check(int i,int j);//Revisa si es posible colocar una nueva reina en la posición (i,j)
   int run(int n);//Recursivamente genera una solución al problema 
             
};






