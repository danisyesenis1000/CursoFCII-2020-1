import matplotlib.pyplot as plt 
import matplotlib.image as mgimg
from matplotlib import animation
import os
n_imagenes=os.listdir('figuras/')
frames = []
for i in range (len(n_imagenes)):
    frames.append('figuras/'+str(i)+'.png')




fig = plt.figure()

myimages = []
plt.axis('off')
for p in frames:
    fname = p
    img = mgimg.imread(fname)
    imgplot = plt.imshow(img)
    myimages.append([imgplot])


my_anim = animation.ArtistAnimation(fig, myimages, interval=200, blit=True, repeat_delay=1000)


my_anim.save("gaus_seidel_v30_a10.mp4")

