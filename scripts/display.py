import sys
import numpy as np
import matplotlib.pyplot as plt

data = sys.stdin.buffer.read()
frame = np.frombuffer(data, dtype=np.uint16)

resolution = int(sys.argv[2])
frame = frame.reshape(resolution,resolution)

#cmap = plt.cm.gist_heat
#cmap = plt.cm.magma
cmap = plt.cm.binary
plt.imsave(sys.argv[1]+".png",frame,cmap=cmap)