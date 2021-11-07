import sys
import numpy as np
import matplotlib.pyplot as plt

resolution = int(sys.argv[1])
frame = []
with open("julia.dat") as data:
	for line in data:
		frame.append(list(map(int,line.strip().split(","))))

cmap = plt.cm.gist_heat
plt.imsave("test.png",frame,cmap=cmap)