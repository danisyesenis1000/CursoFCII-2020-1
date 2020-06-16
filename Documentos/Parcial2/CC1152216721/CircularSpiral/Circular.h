//Circular class definition. Member functions defined in Circular.cpp
#include <iostream>
#include <iomanip>
#include <string>

#define _USE_MATH_DEFINES
#include <cmath>

#define NumPrint std::fixed << std::setprecision(3) << std::scientific

//Prevent multiple inclusion of header
#ifndef CIRCULAR_H
#define CIRCULAR_H

//Circular class definition
class Circular
{
  public:
    Circular(double, double, double); //Constructor
    ~Circular(); //Destructor
    
    //Set functions
    void setRadius(double); //sets the radius of the circle
    void setAngFreq(double); //sets the angular frequency
    void setPhase(double); //set the phase term of the motion
    
    //Get functions
    double getRadius() const; //gets the radius of the circle
    double getAngFreq() const; //gets the angular frequency
    double getPhase() const; //get the phase term of the motion
    
    //functions generating the time evolution for the motion
    double xpos(double); //x-position as a function of time
    double ypos(double); //y-position as a function of time
    
    //additional functions
    void setTotalTime(double); //sets the total time
    void setDeltaT(double); //sets the time interval
    void setPeriodFactor(unsigned int); //period factor
    void setQuantInterv(unsigned int); //quantity of intervals
    
    void setNSubinterv(unsigned int); //sets the number of intervals
    
    double getTotalTime() const; //gets the total time
    double getDeltaT() const; //gets the time interval
    unsigned int getPeriodFactor() const; //gets the period factor
    unsigned int getQuantInterv() const; //gets the quant. of intervals
    
    void motionParams(); //motion parameters for the execution
    
  private:
    //main parameters
    double radius;
    double angFreq;
    double phase;
    
    //secondary parameters
    double totalTime;
    unsigned int nSubinterv;
    double deltaT;
    
    //scale parameters
    unsigned int periodFactor, quantInterv;
    
}; //end class Circular

#endif
