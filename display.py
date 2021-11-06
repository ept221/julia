import sys
import numpy as np
import matplotlib.pyplot as plt

resolution = int(sys.argv[1])
frame = np.loadtxt("julia.dat").reshape(resolution,resolution)
cmap = plt.cm.gist_heat
plt.imsave("test.png",frame,cmap=cmap)