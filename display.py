import sys
import numpy as np
import matplotlib.pyplot as plt

frame = []
for line in sys.stdin:
	frame.append(list(map(int,line.strip().split(","))))

#cmap = plt.cm.gist_heat_r
#cmap = plt.cm.magma
cmap = plt.cm.binary
plt.imsave(sys.argv[1]+".png",frame,cmap=cmap)