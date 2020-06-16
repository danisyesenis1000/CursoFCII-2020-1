#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <unistd.h>

using namespace std;

int EnterNumber(); //Checks if the number entered is a valid option
void EvaluateGuess(int, int); //Checks if the number enteres is greater or less than the number to be guessed
bool Play(); //Plays the game

int main(){
  bool KeepPlaying = true;

  while (KeepPlaying){ //Plays until the player doesn't want to play anymore

    KeepPlaying = Play();
  }
  return 0;
}

bool Play(){
  int Guess, Number, Answer;
  
  srand(time(NULL));

  Number = rand()%1000 + 1; //random number between 1 and 1000

  cout << "Let's start, make your first guess. Remember that the number must be between 1 and 1000" << endl;

  Guess = EnterNumber();
  EvaluateGuess(Guess, Number);
  
  while (Guess != Number){
    Guess = EnterNumber();
    EvaluateGuess(Guess, Number);
  }
  
  cout << "Want to play again? 0: No, 1: Yes. " << endl;

  cin >> Answer;

  if (Answer == 0){
    return false;
  }

  else if (Answer == 1){
    return true;
  }

  else {
    cout << "Unvalid option. Next game cancelled." << endl;
    return false;
  }
}

void EvaluateGuess(int g, int n){
  
  if (g > n){
    cout << "Your guess was greater than the number you must guess." << endl;
  }

  else if (g < n){
    cout << "Your guess was less than the number you must guess." << endl;
  }

  else {
    cout << "Great! You guessed" << endl;
    
    }
}
int EnterNumber(){
  
  bool Input = true;
  
  while (Input){
    
    int g;
    cin >> g;

    if (g > 0 && g <= 1000){
      Input = false;
      
      return g;
    }

    else {
      cout << "The number you entered was invalid, please try again" << endl;
    }
    
  }
}
