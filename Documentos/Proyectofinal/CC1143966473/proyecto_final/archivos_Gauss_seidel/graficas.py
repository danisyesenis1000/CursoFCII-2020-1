import pandas as pd
import numpy as np
df=pd.read_csv('solucion.txt', sep='|')
#print(df.head())

d=np.where(df['x[i]']==100)[0]
print(d)
a=0
b=d[0]
for i in range(len(d)):
    np.savetxt('archivos_finales/t_'+str(i)+'.txt', df[a:b+1],delimiter='|')
    #df[a:b+1])
    a=d[i]+1
    if i<len(d)-1:
        b=d[i+1]
#np.savetxt(r'c:\data\np.txt', df.values, fmt='%d', delimiter='\t')