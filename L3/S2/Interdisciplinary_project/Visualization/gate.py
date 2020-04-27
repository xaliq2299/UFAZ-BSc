import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import sys
import time

def gate_func(x, param):
	return float(param[2]) / ( 1 / float(param[1]) * ( ( x - float(param[0]) )**( 2 * float(param[3]) ) ) + 1 )

##f = open(sys.argv[1], "r")
lowerB, upperB, step = -10, 10, 0.1
x = np.arange(lowerB, upperB + step, step)
sum_y = np.zeros(len(x))

fig = plt.figure()
ax = fig.add_subplot(1,1,1)
#ax = plt.axes(xlim=(-10, 10), ylim=(-10, 10))
#line, = ax.plot([], [])

def update(i):
	sum_y=np.zeros(len(x))
	f = open(sys.argv[1], "r")
	#param = f.readline().split(',')
	param=f.readlines()
#	print(param)
	zeros=np.zeros(len(x))
	for string in param:
		y=gate_func(x, string.split(","))
		sum_y=np.add(sum_y, y)
		#ax = plt.axes(xlim=(-10, 10), ylim=(-10, 10))
	ax.plot(x,sum_y)
	time.sleep(1)
	ax.clear()
		
	ax.plot(x,zeros)
		#time.sleep(0.5)
		
	#ax.clear()
		#line.set_data(x, sum_y)
		
	
	#try:
	#	y = gate_func(x, param[-1].split(","))
	#	sum_y = np.add(sum_y, y)
	#except Exception as e:
	#	print(end="")
	#line.set_data(x, sum_y)
	#for i in range(len(sum_y)):
	#	sum_y[i]=0
	f.close()
	# time.sleep(1)

anim = animation.FuncAnimation(fig, update, interval=1000)
plt.show()
