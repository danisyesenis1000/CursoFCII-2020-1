#!/usr/bin/env python
# coding: utf-8

import pandas as pd #importamos las librerias 
import matplotlib.pyplot as plt # Importamos los datos 
data1 = pd.read_csv('Crank-Nicolson.txt',sep=" ", header=None, names=["a", "b", "c","d"])
data2 = pd.read_csv('Diferencias_progresivas.txt',sep=" ", header=None, names=["a", "b", "c","d"])
data3 = pd.read_csv('Diferencias_regresivas.txt',sep=" ", header=None, names=["a", "b", "c","d"])
print(data3)


x1=[i for i in data1["a"]] # extraemos los datos para grafica
w1=[i for i in data1["b"]]
r1=[i for i in data1["c"]]

#======================================
w2=[i for i in data2["b"]]

#=====================================
w3=[i for i in data3["b"]]


# In[3]:


plt.rcParams["figure.figsize"] = (12,10) #hacemos la grafica
plt.plot(x1,r1,linewidth=1.5, linestyle="-",color='black',label="Exacta") # grafica exacta
plt.plot(x1,w1,linewidth=1.5, linestyle="--",color='g',label="Crank-Nicolson") # grafica Crank-Nicolson
plt.plot(x1,w2,linewidth=1.5, linestyle="--",color='b',label="Dif_progresivas") # grafica diferencias progresivas
plt.plot(x1,w3,linewidth=1.5, linestyle="--",color='r',label="Dif_regresivas") # grafica diferencias regresivas
plt.xlabel("x")
plt.legend()
plt.title("Problema de difusion")
plt.savefig('difusion.png')
plt.show()




