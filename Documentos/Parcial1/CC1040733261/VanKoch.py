#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Jun 24 13:20:41 2020

@author: danis
"""


#!/usr/bin/env python3
# -*- coding: utf-8 -*-
 
from math import sin, cos, pi
import matplotlib.pyplot as plt
import matplotlib
 # genera el cierre de los 3 segmentos cerrados  del copo de Von Koch
def kochSnowFlake(l, n):
    x_vertex1 = 0
    y_vertex1 = 0
     
    x_vertex2 = l * cos ( 2 * pi/3)
    y_vertex2 = l * sin(2 * pi/3)
     
    x_vertex3 = l * cos (pi/3)
    y_vertex3 = l * sin(pi/3)
     
    kochCurve(x_vertex1, y_vertex1, x_vertex2, y_vertex2, n)
    kochCurve(x_vertex2, y_vertex2, x_vertex3, y_vertex3, n)
    kochCurve(x_vertex3, y_vertex3, x_vertex1, y_vertex1, n)
     
    return
         
def kochCurve(xi, yi, xf, yf, n):
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
 
        kochCurve(xi,yi,x1,y1,n-1)
        kochCurve(x1,y1,x2,y2,n-1)
        kochCurve(x2,y2,x3,y3,n-1)
        kochCurve(x3,y3,xf,yf,n-1)
         
    return
   
plt.figure("Koch snowflack")
kochSnowFlake(200,5) # range 1 -6
plt.show()