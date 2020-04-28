#ifndef BOARD_H
#define BOARD_H

#define N 8
#include <iostream>
#include <iomanip>

using namespace std;

class Board{

 protected:
  int board[N][N]; //the array containg Board's information

 public:
  Board();

  void InitBoard(void);  //initializes the board with zeros
  void PrintBoard(void); 

  
  int GetTileInfo(int, int); //Shows if the horse has already passed through a tile (and the corresponding turn) 
  void UpdateTile(int, int, int); //Updates the status of a tile
};

#endif
