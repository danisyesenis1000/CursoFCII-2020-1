#Class "Knight"

1. Compilation: g++ MoveKnight.cpp Knight.cpp -o MoveKnight.exe

2. Execution: ./MoveKnight.exe

3. The program does not solve the problem (to which the answer is afirmative: IT IS POSSIBLE TO COVER THE ENTIRE BOARD WITH THE KNIGHT PASSING ONLY ONCE PER SQUARE), however no attempts were made to see the answer from other sources, as it must be achieved by a simple method reproducible in the algorithm.

Attempts to write a motion pattern include:

* Picking up always the square nearest to one of the borders (for the top and bottom cases, this is achieved sorting the array of possible squares "availSquares").

* Moving in such a way of chosing always the square that is as near to the center as possible.

* Dividing the board in 16 regions of size 4 × 4 and moving in such a way that the next move always implies a counter-clockwise navigation around the board.

* Moving to the square whose coordinates add up to the smallest value.

* Alternating motion: 
- Once in L and once in ¬
- Once in L and twice in ¬, or once in ¬ and twice in L

None of the above produced a satisfactory output after many trials.
