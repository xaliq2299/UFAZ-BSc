import random
import math
import numpy as np

def shuffleTrainingData(dataSet):
	indexes = np.random.permutation(dataSet.shape[0])
	return dataSet[indexes]

def initMatrix(row, column):
	M = [[] for i in range(row)]
	for i in range(row):
		for j in range(column):
			M[i].append(random.uniform(-.0001,.0001))
	return np.array(M, dtype = np.float32)

def loadAttributesAndLabels(dataSet, dataIndex, classes, batchSize, features):
	X = np.zeros([features, batchSize])
	Y = np.zeros([classes, batchSize])
	for i in range(batchSize):
		for j in range(features):
			X[j][i] = dataSet[dataIndex+i][j]
		if dataSet[dataIndex+i][-1] == 'Iris-setosa':
			ind=0
		elif dataSet[dataIndex+i][-1] == 'Iris-versicolor':
			ind=1
		else: # 'Iris-virginica'
			ind=2
		Y[ind][i] = 1
	return X, Y


def tanh(Z):
	return (np.exp(2 * Z) - 1) / (np.exp(2 * Z) + 1)

def tanhDeriv(Z):
	return np.subtract(1, np.power(Z,2))

def relu(Z):
	for i in range(len(Z)):
		for j in range(len(Z[i])):
			if Z[i][j] < 0:
				Z[i][j] = 0
	return Z

def reluDeriv(Z):
	for i in range(len(Z)):
		for j in range(len(Z[i])):
			if Z[i][j] > 0:
				Z[i][j] = 1
			else:
				Z[i][j] = 0
	return Z

def floatMultMatrix(A, n):
	for i in range(len(A)):
		for j in range(len(A[i])):
			A[i][j] = A[i][j] * n
	return A

def convertProb(Y):
	Y = np.transpose(Y)
	for i in range(len(Y)):
		maxV = max(Y[i])
		for j in range(len(Y[i])):
			if Y[i][j] == maxV:
				Y[i][j] = 1
				continue
			Y[i][j] = 0
	return np.transpose(Y)

def compareOutput(A, B):
	A = np.transpose(A)
	B = np.transpose(B)
	counter = 0
	for i in range(len(A)):
		if np.array_equal(A[i],B[i]):
			counter += 1
	return counter

# P-preedicted, A-actual
def compareOutputMetrics(P, A):
	TP = 0
	TN = 0
	FP = 0
	FN = 0
	P = np.transpose(P)
	A = np.transpose(A)
	for i in range(len(A)):
		if P[i][0] and A[i][0]:
			TP += 1
		if P[i][1] and A[i][1]:
			FN += 1
		if P[i][0] and A[i][1]:
			FP += 1
		if P[i][1] and A[i][0]:
			FN += 1
	return TP, TN, FP, FN


def crossEntropy(yHat, y):
	cost = 0.
	for i in range(len(y)):
		for j in range(len(y[0])):
			cost += y[i][j]*np.log(yHat[i][j])
	return -(cost/len(y[0]))

def calcSumOfB(M, batchSize):
	M = np.sum(M, axis=1)/batchSize
	temp = np.zeros((len(M),1))
	for i in range(len(M)):
		temp[i][0] = M[i]
	return temp