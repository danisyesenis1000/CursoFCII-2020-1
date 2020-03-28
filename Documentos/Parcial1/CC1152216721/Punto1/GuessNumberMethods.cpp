#include"GuessNumberHeader.h"

//FUNCTIONS AND METHODS

//Constructor
GuessGame::GuessGame()
{
  std::cout << "****************************" << std::endl;
  std::cout << "* Starting the Guess Game. *" << std::endl;
  std::cout << "****************************" << std::endl;
}

/*
Converts the user input from character string to unsigned short integer
verifying the following situations:
1. Input fail, via std::cin.fail()
2. "End of File" fail, via std::cin.eof()
3. UserInput not having any of the decimal digits {0,1,2,3,4,5,6,7,8,9}
or having different characters to all of them.

The value processed is given to the variable "Guess"
*/
void GuessGame::GuessInput(std::string UserInput)
{
  //Verification of problem situations
  while (std::cin.fail() ||
         std::cin.eof() ||
         UserInput.find_first_not_of("0123456789") != std::string::npos)
  {
    //If user input is not empty but has characters different from the
    //decimal digits, clear the input prompt and ask for a new value
    if (UserInput.find_first_not_of("0123456789") == std::string::npos)
    {
      std::cin.clear();
      std::cin.ignore(256, '\n');
    }
    std::cout << "Invalid input. Enter a number again (0 to exit): ";
    std::getline(std::cin, UserInput);
  }

  //Convert UserInput from character string to unsigned short integer
  Guess = std::stoul(UserInput, nullptr, 0);
}

/*
Generation of a pseudorandom unsigned short integer on [Lower, Upper].
First, set the bounds for the interval according to variables defined
at "GuessNumberExecution.cpp"
*/
void GuessGame::SetLowerAndUpper(unsigned short int RuntimeLower, 
                                 unsigned short int RuntimeUpper)
{
  Lower = RuntimeLower;
  Upper = RuntimeUpper;
}

void GuessGame::MachineRandomChoice()
{
  //Initialization of pseudorandom generation
  std::random_device RandomDevice;
  std::mt19937 Generator(RandomDevice());
  std::uniform_int_distribution<> Distribution(Lower, Upper);

  //Assignation
  MachineRandom = Distribution(Generator);
  
  //OUTPUT for testing purposes.
  //std::cout << "\nMachine Random Choice: " << MachineRandom << std::endl;
}

//Decides if the input is valid, or if the user wants to finish the execution
void GuessGame::ProcessInput(std::string UserNumber)
{
  std::cout << "Enter a number (0 to exit): ";
  std::getline(std::cin, UserNumber);

  //Write user input as "unsigned short int" to variable "Guess"
  GuessInput(UserNumber);

  //If user input equals 0, finish execution
  if (Guess == 0)
  {
    FinishGame();
  }
}

//Finish the game if the user enters 0 or "n" according to the case
void GuessGame::FinishGame()
{
  std::cout << "Execution finished." << std::endl;
  exit(0);
}

//Compare user input to machine's generated number and decide how to proceed
void GuessGame::Comparison(unsigned short int Guess, unsigned short int MachineRandom)
{
  //Comparison stage: success
  if (Guess == MachineRandom)
  {
    std::cout << "**********************************" << std::endl;
    std::cout << "* Congratulations! Correct guess *" << std::endl;
    std::cout << "**********************************" << std::endl;  
    std::cout << "\nDo you want to play again? [y/n]: ";
    std::getline(std::cin, PlayOrEnd);
    
    if (PlayOrEnd == "y")
    { //Generate a new pseudorandom number and execute the comparison and input again
      MachineRandomChoice();
      ExecuteGame();
    }
    
    else if (PlayOrEnd == "n")
    { //Finish the game
      FinishGame();
    }
  }
  
  //Comparison stage: Guess below machine's number
  else if (Guess < MachineRandom)
  {
    std::cout << "\nYour guess number is less than machine's number. Try again." << std::endl;
    ExecuteGame();
  }

  //Comparison stage: Guess above machine's number  
  else if (Guess > MachineRandom)
  {
    std::cout << "\nYour guess number is greater than machine's number. Try again." << std::endl;
    ExecuteGame();
  }
}

//Continued execution of user input and comparison with machine's generated number
void GuessGame::ExecuteGame()
{ 
  //Process input from user
  ProcessInput(UserNumber);
  
  //Compare user input and machine's number
  Comparison(Guess, MachineRandom);
}
