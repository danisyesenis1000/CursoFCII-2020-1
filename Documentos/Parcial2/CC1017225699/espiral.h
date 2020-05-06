#include <string>
#include "circular.h"
// Sub class inheriting from Base Class(Parent) 
class espiral : public circular 
{
public:
    espiral(double, double, double, double, double, double); // z0, v
    ~espiral();
    void setZ0( double );
    void setV( double );
    void setZpos( double, double,double); 
    double getZ0();
    double getV();
    double getZpos();
private:
    double EspZ0;
    double EspV;
    double EspZpos;
    
     
};




