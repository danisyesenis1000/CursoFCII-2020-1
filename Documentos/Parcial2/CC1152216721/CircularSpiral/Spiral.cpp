//Class Spiral member-function definitions
#include "Spiral.h"

Spiral::Spiral(double r, double omega, double phi, double z0, double vz)
  : Circular(r, omega, phi)
{ //CONSTRUCTOR

  //kinematic parameters
  setInitialZpos(z0);
  setZvelocity(vz);
  
} //end Spiral constructor

Spiral::~Spiral()
{ //DESTRUCTOR
  std::cout << "End of spiral motion." << std::endl;
} //end Spiral destructor

/*
SET FUNCTIONS
*/
void Spiral::setInitialZpos(double z0)
{ //sets initial z-position
  initialZpos = z0;
} //end function setInitialZpos

void Spiral::setZvelocity(double vz) 
{ //sets velocity in the z-direction
  zVelocity = vz;
} //end function setZvelocity
    
/*
get functions
*/
double Spiral::getInitialZpos() const
{ //gets initial z-position
  return initialZpos;
} //end function getInitialZpos

double Spiral::getZvelocity() const
{ //gets velocity in the z-direction
  return zVelocity;
} //end function getZvelocity
    
/*
generate motion in the z-direction
*/
double Spiral::zpos(double t)
{ //z-position as a function of time
  return getInitialZpos() + getZvelocity() * t;
} //end function zpos
