#include<iostream>
#include<iomanip>
#include<random>
#include<string>

//CLASS DEFINITION
class GuessGame
{
  public:
    GuessGame();
    void GuessInput(std::string);
    void SetLowerAndUpper(unsigned short int, unsigned short int);
    void MachineRandomChoice();
    void ProcessInput(std::string);
    void FinishGame();
    void Comparison(unsigned short int, unsigned short int);
    void ExecuteGame();
    
    //Lower and upper bound for the pseudorandom number
    unsigned short int Lower, Upper;
    
  private:  
    //Input Variables
    std::string UserNumber;
    unsigned short int MachineRandom;
    unsigned short int Guess;
  
    //Decision control variable
    std::string PlayOrEnd;
};
