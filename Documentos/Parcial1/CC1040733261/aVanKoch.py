
 
from math import sin, cos, pi
import matplotlib.pyplot as plt
import matplotlib
 
# Función para crear  copo de Von Koch
def copoVonkoch(l, n):
    #generando primero los lados de un primer triangulo
    x_vertice1 = 0
    y_vertice1 = 0
     
    x_vertice2 = l * cos ( 2 * pi/3)
    y_vertice2 = l * sin(2 * pi/3)
     
    x_vertice3 = l * cos (pi/3)
    y_vertice3 = l * sin(pi/3)
    
    #llamando la curva de von koch para aplicarla sobre cada lado de los triangulos
    curvaVonkoch(x_vertice1, y_vertice1, x_vertice2, y_vertice2, n)
    curvaVonkoch(x_vertice2, y_vertice2, x_vertice3, y_vertice3, n)
    curvaVonkoch(x_vertice3, y_vertice3, x_vertice1, y_vertice1, n)
     
    return
         
def curvaVonkoch(xi, yi, xf, yf, n):
    #Dubujo de los 3 segmentos segun la cantidad n
    if n==0:
       plt.plot([xi,xf],[yi,yf])
    #genera los 3 segmentos para la curva de Von Koch         
    elif n>0:
        x1 = xi + (xf - xi) / 3.0
        y1 = yi + (yf - yi) / 3.0
 
        x3 = xf - (xf - xi) / 3.0
        y3 = yf - (yf - yi) / 3.0
         
        x2 = (x1 + x3) * cos (pi/3) - ( y3 - y1) * sin (pi/3)
        y2 = (y1 + y3) * cos (pi/3) + ( x3 - x1) * sin (pi/3) 
        
        #llamado de la funcion dentro de la misma función, 
        #pasando los valores acabados de  crear sucesivamente 
        #eso es aplicar recurcion 
        curvaVonkoch(xi,yi,x1,y1,n-1)
        curvaVonkoch(x1,y1,x2,y2,n-1)
        curvaVonkoch(x2,y2,x3,y3,n-1)
        curvaVonkoch(x3,y3,xf,yf,n-1)
         
    return
   
plt.figure("Koch snowflack")
copoVonkoch(200,2) # range 1 -6
plt.show()