//Circular an Spiral classes implementation
#include <iostream>
#include <fstream>
#include <time.h>
#include <unistd.h>

// Self-defined classes
#include "Circular.h"
#include "Spiral.h"

int main()
{
  /*
  FIRST PART: CIRCULAR MOTION
  */
  std::cout << "****************\n"
            << "Circular test: \n"
            << "****************";
            
  //data file creation
  std::ofstream circularFile;
  circularFile.open("output/Circular.dat");
  
  //object attributes
  double radius = 1.0;
  double angFreq = 1.0;
  double phase = 0.0;
  
  //instantiate a "Circular" object
  Circular CircPart(radius, angFreq, phase);
  
  double CircMotionT = 0.0; //motion time accumulator
  
  //MUST EXECUTE: prompt user to confirm motion parameters
  CircPart.motionParams();
  
  //first line of the file: column names
  circularFile << "Time (a-t-u) \t x (a-l-u) \t y (a-l-u)\n";
  
  do
  { //motion: print x and y coordinates
    circularFile << NumPrint << CircMotionT << "\t"
                 << NumPrint << CircPart.xpos(CircMotionT) << "\t"
                 << NumPrint << CircPart.ypos(CircMotionT) << "\n";
              
    //advance time value at steps of deltaT
    CircMotionT += CircPart.getDeltaT();
    
    //stop condition: time reaches the stablished total time
  } while ( CircMotionT < CircPart.getTotalTime() );
  
  //close data file
  circularFile.close();
  std::cout << "data saved to output/Circular.dat" << std::endl;
  usleep(1000000); //wait 1000000 microseconds
  
  /*
  SECOND PART: SPIRAL MOTION
  */
  std::cout << "\n****************\n"
            << "Spiral test: \n"
            << "****************";
  
  //data file creation
  std::ofstream spiralFile;
  spiralFile.open("output/Spiral.dat");
  
  //object additional attributes
  double z0 = 0.0; //initial z-position (in units of length)
  double vz = 1.0; //initial z-velocity (in units of length per unit time)
  
  //instantiate a "Spiral" object
  Spiral SpirPart(radius, angFreq, phase, z0, vz);
  
  double SpirMotionT = 0.0; //motion time accumulator
    
  //MUST EXECUTE: prompt user to confirm motion parameters
  SpirPart.motionParams();
  
  //first line of the file: column names
  spiralFile << "Time (a-t-u) \t x (a-l-u) \t y (a-l-u) \t z (a-l-u)\n";
  
  do
  { //motion: print x, y and z coordinates
    spiralFile << NumPrint << SpirMotionT << "\t"
               << NumPrint << SpirPart.xpos(SpirMotionT) << "\t"
               << NumPrint << SpirPart.ypos(SpirMotionT) << "\t"
               << NumPrint << SpirPart.zpos(SpirMotionT) << "\n";
              
    //advance time value at steps of deltaT
    SpirMotionT += SpirPart.getDeltaT();
    
        
    //stop condition: time reaches the stablished total time
  } while ( SpirMotionT < SpirPart.getTotalTime() );
  
  //close data file
  spiralFile.close();
  std::cout << "data saved to output/Spiral.dat" << std::endl;
  
  return(0);
}
