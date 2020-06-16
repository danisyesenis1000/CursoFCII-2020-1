#include"GuessNumberHeader.h"

int main()
{
  //Object creation
  GuessGame GuessPlay;
  
  //Lower and Upper bounds for the interval in which pseudorandom
  //number is to be generated
  unsigned short int RuntimeLower = 1;
  unsigned short int RuntimeUpper = 1000;
  
  //Setting the former parameters to inner variables
  GuessPlay.SetLowerAndUpper(RuntimeLower, RuntimeUpper);
  
  //First run: generation of random value chosen by computer
  GuessPlay.MachineRandomChoice();
  
  //Play the game until the user makes the right decision or leaves
  GuessPlay.ExecuteGame();
  
  return(0);
}
