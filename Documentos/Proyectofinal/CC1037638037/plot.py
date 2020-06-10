import matplotlib
#matplotlib.use('Qt4agg') 
matplotlib.use("Agg")

#plt.rcParams['animation.ffmpeg_path'] = 'C:/ffmpeg/bin'
import numpy as np
import sys
import os
from pathlib import Path



import matplotlib.pyplot as plt
import matplotlib.animation as animation
 

def close(self):
	exit()

from pathlib import Path



main_folder=str(sorted(Path("asim_out").iterdir(), key=os.path.getmtime)[-1])
print(main_folder)
prm_txt=np.loadtxt(main_folder+'/prm.txt')
agents_dat=np.loadtxt(main_folder+'/agents_dat.txt')
resources_dat=np.loadtxt(main_folder+'/resources_dat.txt')
prices_dat=np.loadtxt(main_folder+'/prices_dat.txt')


N_steps=int(prm_txt[0]);
N_agents=int(prm_txt[1]);
N_resources=int(prm_txt[2]);
Lx=int(prm_txt[4]);
Ly=int(prm_txt[5]);
jf=int(prm_txt[6]);


writer = animation.FFMpegWriter(fps=int(prm_txt[3]))


fig = plt.figure()
gs = fig.add_gridspec(5, 7)
ax1 = fig.add_subplot(gs[:5,:4])
ax2 = fig.add_subplot(gs[3:, 4:])
ax3 = fig.add_subplot(gs[1:3, 4:6])

ax1.set_xlim(0,Lx)
ax1.set_ylim(0,Ly)


with writer.saving(fig, main_folder+"/vid.mp4", dpi=200):
	
	
	well_list=[[] for n in range(N_agents)]
	prices_list=[]
	
	
	for n in range(0,N_steps,jf):
		print(n)

		prices_list.append(prices_dat[n])

	
		ax1.annotate("n="+str(n), (1, 1))
		for i in range(N_agents):
			
			p=agents_dat[n*N_agents+i]
			#ax1.scatter(p[0],p[1],color='b')

			ax1.annotate(str(i), (p[0]-2*i, p[1]),size=10)

			ax1.annotate(str(int(p[2]))+","+str(int(p[3])), (p[0], p[1]-2*i),size=7)
			ax1.annotate(str(int(p[2]))+","+str(int(p[3])), (p[0], p[1]-2*i),size=7)
	
			well_list[i].append(p[4])
			
	
		for i in range(N_resources):
			p=resources_dat[n*N_resources+i]
			ax1.scatter(p[0],p[1],color='forestgreen')
			#ax1.annotate(str(int(p[2]))+","+str(int(p[3])), (p[0]-3, p[1]+1),size=8)

		
		ax1.grid()
		
	
		for n in range(N_agents):
			ax2.grid()
			ax2.plot(well_list[n],label=str(n))
			ax2.legend()



		ax3.grid()
		ax3.plot(prices_list)
			
		
		writer.grab_frame()
		ax1.clear()
		ax2.clear()
		ax3.clear()

		ax1.set_xlim(0,Lx)
		ax1.set_ylim(0,Ly)

os.system("C:\\Users\\camilo\\Desktop\\"+main_folder+"/vid.mp4")



	
	
	
	