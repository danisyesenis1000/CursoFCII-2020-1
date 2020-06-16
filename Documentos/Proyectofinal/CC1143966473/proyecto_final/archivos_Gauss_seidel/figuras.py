import pandas as pd
import numpy as np
import os
import matplotlib.pyplot as plt
n_imagenes=os.listdir('archivos_finales')
print(len(n_imagenes))
for i in range(len(n_imagenes)):
    colnames=['x[i]','V[i]','Psi[i]','Chi[i]','Psi2[i]'] 
    df=pd.read_csv('archivos_finales/t_'+str(i)+'.txt', sep='|',names=colnames, header=None)
    plt.figure(figsize=(15,15))
    plt.plot(df['x[i]'],df['V[i]'],linewidth=3,color='r')
    plt.plot(df['x[i]'],df['Psi2[i]'],linewidth=3,color='g')
    plt.ylim(-0.2,0.5)
    plt.xlim(-30,30)
    plt.xlabel('X',fontsize=30)
    plt.ylabel(r'${ \left| \Psi  \right|  }^{ 2 }$',fontsize=30)
    plt.title("Dispersi"+r'$\acute { o }$'+"n de un paquete de onda cu"+r'$\acute { a }$'+"ntica",fontsize=30)
    plt.xticks(fontsize=25)
    plt.yticks(fontsize=25)
    plt.savefig("figuras/"+str(i)+".png")
    #plt.show()