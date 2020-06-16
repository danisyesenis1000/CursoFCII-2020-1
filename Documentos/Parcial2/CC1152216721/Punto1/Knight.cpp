//Knight class member-functions definitions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Knight.h" //♘♞ □■ ○●

//constructor
Knight::Knight()
{
  std::cout << "\nStarting the Knight's tour.\n" << std::endl;
  bs = 8; //board size; not a very interesting variable though
  
  //board memory space initialization: rows of vector "strip"
  for (unsigned short int i = 0; i < bs; i++) strip.push_back("0");
  std::vector<std::vector<std::string>> b(bs, strip);
  board = b;
}

//destructor
Knight::~Knight()
{
  std::cout << "\nKnight's tour finished." << std::endl;
}

//set knight colour
void Knight::setPiece()
{ 
  //inverted colours in terminal: black prints as white and vice versa
  std::string kColour; 
  std::cout << "Enter knight colour ('w' for white, 'b' for black): ";
  std::getline(std::cin, kColour);
  
  kColour == "b" ? piece = "♘" : piece = "♞";
}

//get piece
std::string Knight::getPiece() const
{
  return piece;
}

//set initial position
void Knight::setInitPos()
{
  std::string initPosOpt;
  std::cout << "Enter 'r' to set a random initial place for the knight"
            << ",\n   or 'c' to set a custom initial location: ";
  std::getline(std::cin, initPosOpt);
  
  if (initPosOpt == "c")
  {
    unsigned short int initRow, initCol;
    std::cout << "Enter the column number (1 for A, 2 for B, etc.): ";
    std::cin >> initCol;
    
    std::cout << "Enter the row number (1, 2, 3, 4, 5, 6, 7 or 8): ";
    std::cin >> initRow;
    
    row = initRow - 1; //counting from 0 to 7
    col = initCol - 1; //counting from 0 to 7
  }
  
  else
  {
    std::srand(time(NULL));
    row = 0 + rand()%(7 + 1 - 0); //lectures general formula
    col = 0 + rand()%(7 + 1 - 0); //lectures general formula
  }
}

//board generation
void Knight::setBoard()
{
  //loop counters
  unsigned short int i, j;

  for (i = 0; i < bs; i++)
  {
    for (j = 0; j < bs; j++)
    {
      if ( (i + j) % 2 == 0 )
        board[i][j] = "■";
      
      else if ( (i + j) % 2 != 0 )
        board[i][j] = "□";
    }
  }
  board[row][col] = getPiece(); //place chosen piece on its position
}

//printing the board
void Knight::printBoard()
{
  //loop counters
  unsigned short int i, j;
  
  //Header, column letters: A, B, ..., H
  std::cout << "  A B C D E F G H " << std::endl;
  
  for (int i = 0; i < bs; i++)
  {
    std::cout << i+1 << " "; //row number: 1, 2, 3, 4, 5, 6, 7, 8    
    for (int j = 0; j < bs; j++)
    {
      std::cout << board[i][j] << " ";
    }
    std::cout << std::endl; //line break
  }
}

//fill the vector availSquares with allowed squares to move into
void Knight::setAvailSquares()
{
  availSquares.clear(); //empty the vector at each execution
  //vector of allowed step sizes
  std::vector<short int> allowed = {-2, -1, 1, 2};

  //loop counters
  unsigned short int i, j;

  for (i = 0; i < allowed.size(); i++)
  {
    for (j = 0; j < 2; j++)
    {
      short int sgn = 2 * j - 1; //movement can be on any direction
      unsigned short int remainder = 3 - std::abs(allowed[i]); 
      short int alpha = allowed[i]; //movement on rows
      short int betac = sgn * remainder; //movement on columns
      
      //makes sure the movement is valid (inside the board)
      if (row + alpha >= 0 && row + alpha < bs && 
          col + betac >= 0 && col + betac < bs)
      {
        //makes sure the movement is valid (no already visited places)
        if (board[row + alpha][col + betac] != "●" && 
            board[row + alpha][col + betac] != "○")
        {
          //"pair:" vector (x, y) of allowed position
          std::vector<unsigned short int> pair(2); 
          pair = {static_cast<uint8_t>(row + alpha),
                    static_cast<uint8_t>(col + betac)};
                    
          //fill the main vector with each allowed pair 
          availSquares.push_back(pair);
        }
      }
    }
  }
}

//draw circles where the knight has already been on
void Knight::drawOldSquare()
{
  ((row+col)%2 == 0) ? board[row][col] = "●" : board[row][col] = "○";
}

//draw the knight on its new position
void Knight::placeKnight()
{
  board[row][col] = getPiece();
}

//move the knight according to available places
void Knight::immediateMove()
{
  std::cout << "Current position: " << char(col+65) << (row+1) << std::endl;
  
  unsigned short int tempRow = row, tempCol = col;
  
  setAvailSquares();
  
  if (availSquares.size() != 0)
  {
    std::cout << "Possible moves: ";
    for (unsigned short int i = 0; i < availSquares.size(); i++)
    {
      std::cout << char(availSquares[i][1]+65) << (availSquares[i][0]+1) << "  ";
    } std::cout << std::endl;
    
    //CRITICAL SECTION:
    //tried std::sort, std::reverse, std::random_shuffle,
    //non of them were successful. Must not see the answer
    //on internet beforse solving it by own means.
    //A modification here can make the program achieve its goal.
    std::random_shuffle(availSquares.begin(), availSquares.end());
    std::cout << "Choice: " << char(availSquares[0][1]+65) << (availSquares[0][0]+1) << std::endl;
    //END OF CRITICAL SECTION
    
    drawOldSquare();
    row = availSquares[0][0]; col = availSquares[0][1];
    placeKnight();
  }
  
  else {std::cout << "No more possible movements" << std::endl;}
  //std::cout << "; next position: " << char(col+65) << (row+1) << std::endl;
}
