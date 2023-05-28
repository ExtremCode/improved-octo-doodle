import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d
import pandas as pd
import seaborn as sb

f = lambda y: np.array([10*(y[1]-y[0]), y[0]*(28-y[2])-y[1], y[0]*y[1]-8/3*y[2]])
a = 0
b = 10
n = 50
h = (b-a)/n
t = np.zeros(n, dtype=float)
t[0] = a
y = np.zeros((3, n), dtype=float)
y[:, 0] = [0, 1, 20]
for j in range(n-1):
    k1 = h*f(y[:, j])
    k2 = h*f(y[:, j] + k1*h/2)
    k3 = h*f(y[:, j] + k2*h/2)
    k4 = h*f(y[:, j] + k3*h)
    y[:, j+1] = y[:, j] + h/6*(k1 + 2*k2 + 2*k3 + k4)
    t[j+1] = t[j]+h
fig1, ax = plt.subplots()
ax.plot(t,y[0,:])
ax.plot(t,y[1,:])
ax.plot(t,y[2,:])
plt.show()