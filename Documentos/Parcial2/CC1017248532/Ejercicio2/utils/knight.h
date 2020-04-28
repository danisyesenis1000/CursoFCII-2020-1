#ifndef KNIGHT_H
#define KNIGHT_H

#define N 8 //defines the tiles of the board
#include <iostream>

using namespace std;

class Knight{

 private:

  int xpos; //Knight's x position
  int ypos; //Knight's y position
  
  //The next arrays define the movement of the Knight and they work as a pair
  //The knight can move in 8 different ways. 
  
  int MoveX[N] = { 1,  2, 2, 1, -1, -2, -2, -1};
  int MoveY[N] = {-2, -1, 1, 2,  2,  1, -1, -2};
  
  friend class Game; //So Game can access Knight's private variables


 public:
  
  Knight(); //Constructor

  void InitPos(int, int);      //inputs: initial x, initial y
  void UpdatePos(int, int);    //inputs: new x, new y
  void PrintCurrentPos(void);
  int GetXPos(void);   
  int GetYPos(void);
  

    

};

#endif
