
#include <string>
//using std::string;

// Complejo class definition
class Complejo
{
public:
    Complejo( double, double ); 
    Complejo Sum(Complejo C2);
    Complejo Res(Complejo C2);
    double getParteReal();
    double getParteImag(); 
    void displayMessage(); 
private:
    void asigDato(double, double);
    double ParteReal;
    double ParteImag;
};    
