//Class Circular member-function definitions
#include "Circular.h"

Circular::Circular(double r, double omega, double phi)
{ //CONSTRUCTOR
  //Initial prompt
  std::cout << "\nBegining of motion.\n" << std::endl;
  
  //kinematic parameters
  setRadius(r);
  setAngFreq(omega);
  setPhase(phi);
  
  //Additional parameters
  setPeriodFactor(4);
  setQuantInterv(1024);
  
} //end Circular constructor

Circular::~Circular()
{ //DESTRUCTOR
  std::cout << "End of circular motion." << std::endl;
} //end Circular destructor

/*
SET FUNCTIONS
*/
void Circular::setRadius(double r)
{
  radius = r;
} //end function setRadius

void Circular::setAngFreq(double omega)
{
  angFreq = omega;
} //end function setAngFreq

void Circular::setPhase(double phi)
{
  phase = phi;
} //end function setPhase

void Circular::setPeriodFactor(unsigned int f)
{
  periodFactor = f;
}

void Circular::setQuantInterv(unsigned int q)
{
  quantInterv = q;
}

/*
GET FUNCTIONS
*/
double Circular::getRadius() const
{
  return radius;
} //end function getRadius

double Circular::getAngFreq() const
{
  return angFreq;
} //end function getAngFreq

double Circular::getPhase() const
{
  return phase;
} //end function getPhase

unsigned int Circular::getPeriodFactor() const
{
  return periodFactor;
} //end function getPeriodFactor

unsigned int Circular::getQuantInterv() const
{
  return quantInterv;
} //end function getQuantInterv

/*
TIME EVOLUTION OF THE MOTION
*/
double Circular::xpos(double t)
{ //x-position time evolution
  return getRadius() * cos( getAngFreq() * t + getPhase() );
} //end function xpos

double Circular::ypos(double t)
{ //y-position time evolution
  return getRadius() * sin( getAngFreq() * t + getPhase() );
} //end function ypos

/*
ADDITIONAL FUNCTIONS
*/
void Circular::setNSubinterv(unsigned int numberOfInt)
{
  nSubinterv = numberOfInt;
}

void Circular::setTotalTime(double totalT)
{
  totalTime = totalT;
}

void Circular::setDeltaT(double dt)
{
  deltaT = dt;
}

double Circular::getTotalTime() const
{
  return totalTime;
}

double Circular::getDeltaT() const
{
  return deltaT;
}

//Motion parameters
void Circular::motionParams()
{
  double period = (2.0 * M_PI) / getAngFreq();
  double suggTime = getPeriodFactor() * period;
  double suggDeltaT = suggTime / getQuantInterv();
  std::string option;
  
  std::cout 
  << "Given the angular frequency: ω = " << NumPrint << getAngFreq() 
  << " radians per unit time, \nthe corresponding period is: "
  << "T = " << NumPrint << period << " units of time.\n"
  << "\nTHE FOLLOWING DEFAULT PARAMETERS ARE SUGGESTED: \n"
  << "‣ Total time: an integer multiple of the period. In this case,\n"
  << "Total Time = " << getPeriodFactor() << " × period = " << NumPrint 
  << suggTime << " units of time.\n" 
  << "‣ Number of time intervals: " << getQuantInterv()
  << ", each of them with size\n"
  << "Δt = " << NumPrint << suggDeltaT << " units of time.\n"
  << std::endl;
  
  std::cout << "Modify the former parameters? [y/n]: ";
  std::getline(std::cin, option);
    
  if (option == "y")
  {
    double customTime = 0.0;
    unsigned int customNSubinterv = 1;

    std::cout << "Input a new value for the total time: ";
    std::cin >> customTime;
    
    std::cout << "Input a new value for the number of time intervals: ";
    std::cin >> customNSubinterv;
    
    setTotalTime(customTime);
    setNSubinterv(customNSubinterv);
    setDeltaT( customTime / customNSubinterv );
  }
    
  else if (option == "n")
  {
    setTotalTime(suggTime);
    setNSubinterv(getQuantInterv());
    setDeltaT(suggDeltaT);
  }
  
}
