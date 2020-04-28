import NNLib as NN
import numpy as np


class NeuralNet(object):
	"""docstring for NeuralNet"""
	data, W1, W2, b1, b2 = [], [], [], [], []
	W1_toSave, W2_toSave, b1_toSave, b2_toSave = [], [], [], []
	nbHiddenNodes = 0
	nbBatch = 0
	nbClass = 0
	nbFeatures = 0
	eta = 0.05
	bestResult = 0.0001
	filename_weights='best_weights.npz'
	def __init__(self, data, numberOfClasses, batchSize, numberOfHiddenNodes):
		self.data = data
		self.data = self.data.astype(np.float64)
		for i in range(data.shape[1] - 1):
			self.data[:,i] = NN.standartization(self.data[:,i])
		self.nbClass = numberOfClasses
		self.nbBatch = batchSize
		self.nbHiddenNodes = numberOfHiddenNodes
		self.nbFeatures = len(data[0])-1	

		self.W1 = NN.initMatrix(self.nbHiddenNodes, self.nbFeatures)
		self.W2 = NN.initMatrix(self.nbClass, self.nbHiddenNodes)
		self.b1 = NN.initMatrix(self.nbHiddenNodes, 1) # TODO CHECK LATER!! 
		self.b2 = NN.initMatrix(self.nbClass, 1) # TODO CHECK LATER!! 
		
		#self.train(15)
		print()


	def train(self, nbEpoch):
		for i in range(nbEpoch):
			if i%100 == 0 and i!=0:
				self.eta /= 1.5
			data = NN.shuffleTrainingData(self.data)
			trainData, testData = self.dataSplit(data, 0.7)
			self.trainingEpoch(trainData)
			temp = self.testPrediction(testData)
			if temp > self.bestResult:
				self.bestResult = temp
				self.W1_toSave = self.W1
				self.W2_toSave = self.W2
				self.b1_toSave = self.b1
				self.b2_toSave = self.b2


	def trainingEpoch(self, trainData):
		dataIndex = 0
		batchSize = self.nbBatch
		while True:
			if (dataIndex + batchSize) >= len(trainData):
				if dataIndex >= len(trainData):
					break
				batchSize = len(trainData) - dataIndex
			X_train, Y_train = NN.loadAttributesAndLabels(trainData, dataIndex, self.nbClass, batchSize, self.nbFeatures)
			dataIndex += batchSize
			B1 = np.tile(self.b1, (1,batchSize))
			B2 = np.tile(self.b2, (1,batchSize))
			# Feed-Forwards
			Z1 = self.W1@X_train + B1
			A1 = NN.tanh(Z1)
			Z2 = self.W2@A1 + B2
			A2 = NN.tanh(Z2)

			# Back-propogation
			error = A2 - Y_train
			delta2 = error*NN.tanhDeriv(A2)
			self.W2 = self.W2 - self.eta * (delta2@np.transpose(A1))
			self.b2 = self.b2 - self.eta * NN.calcSumOfB(delta2, batchSize)
			delta1 = NN.tanhDeriv(A1)*(np.transpose(self.W2)@delta2)
			self.W1 = self.W1 - self.eta * (delta1@np.transpose(X_train))
			self.b1 = self.b1 - self.eta * NN.calcSumOfB(delta1, batchSize)

	def testPrediction(self, testData):
		# predicted = 0
		TP = 0.001
		TN = 0.001
		FP = 0.001
		FN = 0.001
		dataIndex = 0
		batchSize = self.nbBatch
		while True:
			if (dataIndex + batchSize) >= len(testData):
				if dataIndex >= len(testData):
					break
				batchSize = len(testData)  - dataIndex
			X_train, Y_train = NN.loadAttributesAndLabels(testData, dataIndex, self.nbClass, batchSize, self.nbFeatures)
			dataIndex += batchSize
	
			# Feed-Forward
			Z1 = self.W1@X_train + self.b1
			A1 = NN.tanh(Z1)
			Z2 = self.W2@A1 + self.b2
			A2 = NN.tanh(Z2)
			A2 = NN.convertProb(A2)

			# Compare result
		# 	predicted += NN.compareOutput(A2, Y_train)
		# print('MLP\'s accuracy=' + str(float(predicted/len(testData))*100) + '%')
		# return (float(predicted/len(testData))*100)
			# Compare result
			temp_TP, temp_TN, temp_FP, temp_FN = NN.compareOutputMetrics(A2, Y_train)
			TP += temp_TP
			TN += temp_TN
			FP += temp_FP
			FN += temp_FN
		print('MLP\'s sensitivity =' + str(float(TP/(TP+FN))*100) + '%')
		print('MLP\'s specificity =' + str(float(TN/(TN+FP))*100) + '%')
		print('MLP\'s accuracy=' + str(float((TP+FN)/(TP+TN+FP+FN))*100) + '%')
		print('MLP\'s precision =' + str(float(TP/(TP+FP))*100) + '%\n')
		return (float((TP+FN)/(TP+TN+FP+FN))*100)


	def dataSplit(self, data, trainCoef):
		trainingSize = int(len(data) * trainCoef)
		trainData = data[:trainingSize][:]
		testData = data[trainingSize:][:]
		return trainData, testData

	def dataSave(self):
		# print(str(self.W1_toSave))
		# print(str(self.W2_toSave))
		# print(str(self.b1_toSave))
		# print(str(self.b2_toSave))
		np.savez(self.filename_weights, name1=self.W1, name2=self.W2, name3=self.b1, name4=self.b2)

	def dataLoad(self):
		data = np.load(self.filename_weights) # reading for future use
		self.W1 = data['name1']
		self.W2 = data['name2']
		self.b1 = data['name3']
		self.b2 = data['name4']
		# print(str(self.W1))
		# print(str(self.W2))
		# print(str(self.b1))
		# print(str(self.b2))