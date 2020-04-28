import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import argparse

parser = argparse.ArgumentParser(description='Plot evolution graph')
parser.add_argument('key', metavar='K', type=str,
                    help='choose which mode to plot. C for circular,\
                          E for espiral')

args = parser.parse_args()

if args.key == 'E':
    x, y, z = np.loadtxt('data_espiral.csv', 
                      skiprows=1,
                      delimiter=';',
                      unpack=True)
    
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.plot(x, y, z)
    ax.scatter(x[-1], y[-1], z[-1], c='r')
    plt.show()

if args.key == 'C':
    x, y = np.loadtxt('data_circular.csv', 
                      skiprows=1,
                      delimiter=';',
                      unpack=True)
    
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.plot(x, y)
    ax.plot(x[-1], y[-1], 'or')
    ax.grid()
    plt.show()
