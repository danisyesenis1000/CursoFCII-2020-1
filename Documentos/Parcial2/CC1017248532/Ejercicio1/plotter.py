#!/usr/bin/env python
# coding: utf-8


import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


C = pd.read_csv("datos_circular.csv")
E = pd.read_csv("datos_espiral.csv")



fig = plt.figure(figsize = (5,10))
ax1 = fig.add_subplot(211, projection='3d')
ax2 = fig.add_subplot(212)

ax1.plot(E["x"], E["y"], E["z"])

ax1.set_title("Gráfico de la Espiral")

ax1.set_xlabel("x")
ax1.set_ylabel("y")
ax1.set_zlabel("z")

ax1.set_xticks([])
ax1.set_yticks([])
ax1.set_zticks([])

ax2.plot(C["x"], C["y"])
ax2.set_title("Gráfico del Círculo")
ax2.set_xlabel("x")
ax2.set_ylabel("y")

ax2.set_xticks([])
ax2.set_yticks([])

plt.show()

