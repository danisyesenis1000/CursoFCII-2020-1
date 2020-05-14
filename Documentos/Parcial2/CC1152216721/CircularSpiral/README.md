#Classes "Circular" and "Spiral"

0. An object of the class "Circular" receives three arguments: radius, angular frequency and phase, whereas an object of the class "Spiral" receives five arguments: those of a "Circular" object, plus the inital position in z and its velocity in that direction.

1. Compilation: g++ Motion.cpp Circular.cpp Spiral.cpp -o Motion.exe

2. Execution: ./Motion.exe

3. the gnuplot script "Draw.gp" inside the folder "output" contains the basic instructions with which data files "Circular.dat" and "Spiral.dat" (produced during program execution) lead to "Circular.png" and "Spiral.png".
