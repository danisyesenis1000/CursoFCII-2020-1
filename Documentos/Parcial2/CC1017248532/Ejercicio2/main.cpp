#include "utils/board.h"
#include "utils/knight.h"
#include "utils/game.h"

int main(){
  int x;
  int y;
  
  //They must be between 0 and 7
  x = 3; 
  y = 4;
  
  Game g;
  //  Game g(x,y);  //Uncomment if you want to use initial conditions different from 0
  
    
  g.PlayGame();
  return 0;
}
