#include "utils/game.h"

//In case you want to give the knight your own initial coordinates
Game::Game(int x, int y){ 
  InitX = x;
  InitY = y;
}

//or use this one if you just want your knight to start in the origin
Game::Game(){
  InitX = 0;
  InitY = 0;
}

void Game::InitGame(){
  K.InitPos(InitX, InitY);
  B.InitBoard();
  B.UpdateTile(InitX,InitY,1);
  CurrentMove = 2;  //Since the first move was already taken by the initial condition

}

bool Game::SafeMove(){
    
    //This basically checks if the knight hasn't gone out of bounds,
    //so it doesn't appear in the other side of the array
    
  if ( K.GetXPos() >= 0 && K.GetYPos() >= 0 && K.GetYPos() < N &&\
      K.GetXPos() < N && B.GetTileInfo(K.GetXPos(), K.GetYPos()) == 0){

    return true;
  }
  else {return false;}
					   
}


//The next function is a recurrent function. It is the actual solver of the problem.
int Game::CheckGame(){

  //When the Knight makes 64 correct moves, the function will return a 1 and end the recursion
  if (CurrentMove == N*N + 1) { 
      return 1;
}
  
  for (int i = 0; i < 8; i++){

    //Saving the current position of the horse, in case this move doesn't get us to a solution
    int x = K.GetXPos();
    int y = K.GetYPos();

    K.UpdatePos(x + K.MoveX[i], y + K.MoveY[i]);

    if (SafeMove()){
        
      B.UpdateTile(K.GetXPos(), K.GetYPos(), CurrentMove);
      CurrentMove++;
      
      /* 
       Realize that this will call the function again and again,
       it will telescope into the future of the knight until either the knight wins or
       it runs out of moves that are safe. When that happens the functions returns a 0
       */
      if (CheckGame() == 1){  //this one's only true if 64 moves are achieved
	
	return 1;
      }

      else{
	
    // (continuing from the last comment)
    // and we return every variable to their past-state in order to try again
          
	B.UpdateTile(K.GetXPos(),K.GetYPos(), 0); 
	K.UpdatePos(x, y);
	CurrentMove--;
      }	
    }
    
    else {
      
      K.UpdatePos(x, y); //Because the move wasn't safe, the horse must return to its last state
    }
  }

  return 0;
}

bool Game::PlayGame(){
    
  InitGame();
  if (CheckGame() == 1){
    B.PrintBoard();

  }
  else { //it can happen that the game has no solution from the place you start (not sure though)
    cout << "There is no solution for those inital positions" << endl;
    B.PrintBoard();
  }
}
