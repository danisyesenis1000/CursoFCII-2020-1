#include "utils/board.h"

Board::Board(){};

void Board::InitBoard(){

  for (int i = 0; i < N; i++){

    for (int j = 0; j < N; j++){

      board[i][j] = 0; //assigns the value 0 to each tile, 0 means the knight hasn't passed through this tile
    }
  }
}

void Board::PrintBoard(){

  for (int i = 0; i < N; i++){

    for (int j = 0; j < N; j++){

      cout << setw(3) << board[i][j]; //prints each tile in a pretty way
    }
    cout << endl;
  }
}

int Board::GetTileInfo(int x, int y) { return board[x][y]; }

void Board::UpdateTile(int x, int y, int s) { board[x][y] = s; }
