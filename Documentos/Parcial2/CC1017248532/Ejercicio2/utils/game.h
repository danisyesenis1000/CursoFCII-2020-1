#include "board.h"
#include "knight.h"

class Game{

 private:
  int CurrentMove; //An iterator that fills the board with the corresponding move
  int InitX;       //Initial X for the Knight
  int InitY;       //Initial Y for the Knight
  Board B;          
  Knight K;
  
 public:
  Game(int , int); //Initial positions for the knight
  Game(); //If you want to use default positions (1,1)
  
  void InitGame(void);
  int CheckGame(void);  //Checks if the current game can win
  bool SafeMove(void);  //Checks if a move is safe, i.e, the Knight doesn't get outside the board

  bool PlayGame(void);  
  void PrintWinningGame(void); //prints the game if you won!
};
