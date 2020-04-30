
//using std::string;

// Rectangulo class definition
class reinas
{
public:
    reinas( int ); // radio, omega, alfa, tiempo
    void setdim(int); 
    void printtablero( int [8][8],int);
    bool Psegura(int [8][8], int, int, int);
    bool solRecu(int [8][8], int, int);
    bool solR();
private:

    int D;   
}; 




