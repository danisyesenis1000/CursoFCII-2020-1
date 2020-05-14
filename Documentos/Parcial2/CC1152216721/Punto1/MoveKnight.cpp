//Knight class implementation
#include <iostream>
#include <time.h>
#include <unistd.h>

#include "Knight.h"

int main()
{
  //instantiate a Knight object named "horse"
  Knight horse;
  
  //set the piece colour to be used by the algorithm
  horse.setPiece();
  
  //set the initial position of the piece
  horse.setInitPos();
  
  //prepare the board with the information just entered
  horse.setBoard();
  
  //movement execution
  unsigned short int movCount = 0;
  do
  {
    system("clear"); //clear the screen
    std::cout << "Movement # " << movCount << std::endl; //show counter
    horse.printBoard(); //show the board on screen
    horse.immediateMove(); //make a move
    usleep(1000000); //wait 1000000 microseconds
    
    movCount++; //register the movement
    
    //stop condition: the piece has no available squares to move into
  } while (horse.availSquares.size() != 0);

  return(0);
} //end main function
