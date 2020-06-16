//Spiral class definition. Member functions defined in Spiral.cpp
#include "Circular.h"

//Prevent multiple inclusion of header
#ifndef SPIRAL_H
#define SPIRAL_H

//Spiral class definition
class Spiral : public Circular
{
  public:
    Spiral(double, double, double, double, double); //constructor
    ~Spiral(); //destructor
    
    //set functions
    void setInitialZpos(double); //sets initial z-position
    void setZvelocity(double); //sets velocity in the z-direction
    
    //get functions
    double getInitialZpos() const; //gets initial z-position
    double getZvelocity() const; //gets velocity in the z-direction
    
    //generate motion in the z-direction
    double zpos(double); //z-position as a function of time
    
  private:
    double initialZpos; //initial z-position
    double zVelocity; //velocity in the z-direction
    
}; //end class Spiral

#endif
