import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import sys

f = open(sys.argv[1], "r")
lowerB, upperB, step = -5, 5, 0.5
x = np.arange(lowerB, upperB + step, step)

def lin_func(x, param):
	return float(param[0]) * x + float(param[1])

def read_data():
	res = []
	while True:
		param = f.readline()
		if param == "":
			break
		param = param.split(';')
		res.append(param)
	return res


# fig = plt.figure()
# ax = plt.axes(xlim=(-10, 10), ylim=(-20, 20))
# while True:
# 	param = f.readline()
# 	if param == "":
# 		break
# 	param = param.split(';')	
# 	y = lin_func(x, param)
# 	plt.plot(x, y)

# def update(frame):
	# temp = read_data()
	# for i in temp:
	# 	y = lin_func(x, i)
	# 	plt.plot(x, y)


# anim = animation.FuncAnimation(fig, update, interval=500, blit=False)
# plt.show()

fig = plt.figure()
#creating a subplot 
# ax1 = fig.add_subplot(1,1,1)

while True:
	plt.cla()
	temp = read_data()
	# ax1.clear()
	for i in temp:
		y = lin_func(x, i)
		# plt.plot(x, y)
		plt.plot(x, y)
	# fig.canvas.draw()
	# plt.legend()
	plt.draw()
	plt.show()

	
    
