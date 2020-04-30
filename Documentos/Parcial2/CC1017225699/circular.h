// Circular.h


#include <string>
//using std::string;

class circular
{
public:
    circular( double, double, double, double ); // radio, omega, alfa, tiempo
    ~circular(); 
    void setRadio( double );
    void setOmega( double );
    void setAlfa( double );
    void setTiempo( double );
    void setXpos( double, double, double, double);
    void setYpos( double, double, double, double); 
    double getRadio();
    double getOmega();
    double getAlfa();
    double getTiempo();
    double getXpos();
    double getYpos();
private:    
    double CirRadio;
    double CirOmega;
    double CirAlfa;
    double CirTiempo;
    double CirXpos;
    double CirYpos;
       
}; 
