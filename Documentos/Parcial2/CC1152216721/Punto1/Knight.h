//Knight class definition. Member functions in Knight.cpp
#include <vector>
#include <string>

//avoid multiple inclusion
#ifndef KNIGHT_H
#define KNIGHT_H

class Knight
{
  public:
    Knight(); //constructor
    ~Knight(); //destructor
    
    void setBoard(); //create Board

    void setPiece(); //set knight colour
    std::string getPiece() const; //get knight coloured piece
    
    void setInitPos(); //set the initial position of the piece
    
    void setAvailSquares(); //set the available squares for the piece
    
    void drawOldSquare(); //put a circle on a place already visited
    
    void placeKnight(); //draw the knight on its current position
    
    void immediateMove(); //move the piece to an available places
    
    void printBoard(); //print the chess board
    
    std::vector<std::vector<unsigned short int>> availSquares; //vector
    
  private:
    unsigned short int bs; //board size
    std::string piece; //knight coloured piece
    std::vector<std::string> strip; //vector required to set up a board
    std::vector<std::vector<std::string>> board; //board
    unsigned short int row, col; //knight position 
    
}; //end class Knight

#endif
