#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include "maze.h"

/*
 * functions.cpp
 * 
 * Functions for class Maze.
 * The algorithm used to solve the maze is always following the wall
 * on the right. To do this, aside from position, an orientation
 * is set to know in which direction 'right' is. North is defined
 * to be at the top of the screen.
 * 
 * Requires: maze.h
 * 
 * Carolina Herrera S.
 * Last update: april 27, 2020
 * 
 * */

using namespace std;

void Maze::load( string filename, array<int, 2> start ){
    /* Load maze from file. The characters must be separated by spaces
     * and consist of only '#' and '.'.
     * 
     * input:
     * 
     * string filename: Name of maze file.
     * 
     * array<int, 2> start: array with starting coordinates in the order
     *                      {row, column}.
     * */
    
    ifstream maze_data( filename, ios::in );
    
    if ( maze_data.fail() ){
      cout << "Couldn't read file.'" << endl;
      exit( 1 );
    }
    
    position = start;
    
    if ( start[0] == 0 ) orientation = 'S';
    else if ( start[0] == 11 ) orientation = 'N';
    else if ( start[1] == 0 ) orientation = 'E';
    else if ( start[1] == 11 ) orientation = 'W';
    
    for (int i=0; i<12; i++){
        for (int j=0; j<12; j++){
            
            maze_data >> maze[i][j];
        }
    }
    
    maze_data.close();
}

// To go south, you add one to the rows.
void Maze::go_south(){
    position[0] += 1;
}

// To go north, you subtract one to the rows.
void Maze::go_north(){
    position[0] -= 1;
}

// To go east, you add one to the columns.
void Maze::go_east(){
    position[1] += 1;
}

// To go west, you subtract one to the columns.
void Maze::go_west(){
    position[1] -= 1;
}

// 'Right' depends on which direction you are facing.
// If facing south, 'right' is to the west, etc.
void Maze::go_right(){
    
    switch (orientation){
    
    case 'S':
      go_west();
      orientation = 'W';
      break;
    
    case 'N':
      go_east();
      orientation = 'E';
      break;
    
    case 'E':
      go_south();
      orientation = 'S';
      break;
    
    case 'W':
      go_north();
      orientation = 'N';
      break;

    default:
      cout << "Something went wrong." << endl;
      break;
    }
}


void Maze::go_left(){
    
    switch (orientation){

    case 'S':
      go_east();
      orientation = 'E';
      break;

    case 'N':
      go_west();
      orientation = 'W';
      break;

    case 'E':
      go_north();
      orientation = 'N';
      break;

    case 'W':
      go_south();
      orientation = 'S';
      break;

    default:
      cout << "Something went wrong." << endl;
      break;
    }
}


void Maze::go_straight(){
    
    switch (orientation){

    case 'S':
      go_south();
      break;

    case 'N':
      go_north();
      break;

    case 'E':
      go_east();
      break;

    case 'W':
      go_west();
      break;

    default:
      cout << "Something went wrong." << endl;
      break;
    }
}


void Maze::go_back(){
    
    switch (orientation){

    case 'S':
      go_north();
      orientation = 'N';
      break;

    case 'N':
      go_south();
      orientation = 'S';
      break;

    case 'E':
      go_west();
      orientation = 'W';
      break;

    case 'W':
      go_east();
      orientation = 'E';
      break;

    default:
      cout << "Something went wrong." << endl;
      break;
    }
}

// Resets to last state saved in position_reset and orientation_reset.
void Maze::reset_state(){
    position = position_reset;
    orientation = orientation_reset;
}


// Prints current state of maze on the terminal
void Maze::print_state()
{
    system("clear");
    
    // Asterisk shows current position
    maze[position[0]][position[1]] = '*';
    
    for (int i=0; i<12; i++){
        for (int j=0; j<12; j++){
            
            cout << maze[i][j] << " ";
        }
        cout<< endl;
    }
    
    maze[position[0]][position[1]] = 'X';
    
    system("sleep 0.5");
}


// Maze solver algorithm
void Maze::solve(){
    
    print_state();
    
    go_straight();
    print_state();
    
    // While outside of borders of maze
    while ( position[0] != 0 && position[0] != 11 
            && position[1] != 0 && position[1] != 11 ){
        
        // Save current state
        position_reset = position;
        orientation_reset = orientation;
        
        // First go right
        go_right();
        
        // If there is a wall, reset state and go straight
        if ( maze[position[0]][position[1]] == '#'){
            reset_state();
            go_straight();
            
            // If there is a wall there as well, reset state and go left
            if ( maze[position[0]][position[1]] == '#'){
                reset_state();
                go_left();
                
                // If there is a wall there as well, reset state and go back
                if ( maze[position[0]][position[1]] == '#'){
                    reset_state();
                    go_back();
                }
            }
        }
        
        print_state();
    }
}
