import sys
import numpy as np
import matplotlib.pyplot as plt

data = sys.stdin.buffer.read()
frame = np.frombuffer(data, dtype=np.uint16)

resolution = int(sys.argv[2])
frame = frame.reshape(resolution,resolution)

# See https://matplotlib.org/stable/tutorials/colors/colormaps.html for more color maps
cmap = plt.cm.binary
# cmap = plt.cm.gist_heat
# cmap = plt.cm.magma

plt.imsave(sys.argv[1]+".png",frame,cmap=cmap)