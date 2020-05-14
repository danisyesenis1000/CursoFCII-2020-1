import matplotlib.pyplot as plt
import numpy as np

def seriebinomial(x):
    return 1/(1-x)

datos1,datos2= np.loadtxt('valores.txt',unpack=True) #extrae los datos del documento en dos arreglos. 

xi=1.1
xf=20
dx=0.01
x=np.arange(xi,xf,dx)

plt.figure()
plt.plot(x,seriebinomial(x))
plt.plot(datos1,datos2,'o')
plt.grid()
plt.xlabel("x")
plt.ylabel("y")
plt.title("Grafico de la solución de la funcion lineal")
plt.show()
