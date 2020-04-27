import matplotlib.pyplot as plt
import numpy as np

def abline(slope, intercept):
    """Plot a line from slope and intercept"""
    axes = plt.gca()
    x_vals = np.array(axes.get_xlim())
    y_vals = intercept + slope * x_vals
    plt.plot(x_vals, y_vals, '-')
    plt.show()

import numpy as np

import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style

style.use('fivethirtyeight')

fig = plt.figure()
ax1 = fig.add_subplot(1,1,1)

from random import randint

def animate(i):
            oxu = open("text.csv", "r+")
            l = oxu.readlines()

            # print(l[-1].split(",")[0])
            slope = float(l[-1].split(",")[0])
            intercept = float(l[-1].split(",")[1])

            x_vals = np.array(ax1.get_xlim())
            y_vals = intercept + slope * x_vals

            #ax1.clear()
            colors=['r']
            ax1.plot(x_vals, y_vals, 'g', linewidth=2.5)
            # ax1.plot(x2,y2)

# def initAnim():


ani = animation.FuncAnimation(fig, animate, interval=1000)
plt.show()
