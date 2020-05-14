set terminal png

set output 'Circular.png'
set title 'Circular motion'
set xlabel 'x'
set ylabel 'y'
set grid
plot 'Circular.dat' every ::1 using 2:3 with lines
set size ratio -1

clear

set output 'Spiral.png'
set ticslevel 0
set title 'Spiral motion'
set xlabel 'x'
set ylabel 'y'
set zlabel 'z'
set grid
splot 'Spiral.dat' every ::1 using 2:3:4 with lines
set size ratio -1

replot
