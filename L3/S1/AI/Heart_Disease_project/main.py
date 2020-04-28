from NeuralNet import NeuralNet
import numpy as np

def read_file(filename, separator, headerExist = False):
	data_from_file = []
	f=open(filename,"r")
	if headerExist:
		temp=f.readline().strip()
	while True:
		temp=f.readline().strip()
		if temp=="":
			break
		data_from_file.append(temp.split(separator))
	return data_from_file


def main():
	
	data_from_file = np.array(read_file("heart_disease_dataset.csv", ';', True))
	nbEpochs=int(input("Enter the number of epochs: "))
	neuron = NeuralNet(data_from_file, 2, 8, 5)
	print("Enter \n\"r\" for running tests (",nbEpochs, "epochs ) or \n\"b\" for the best accuracy result of last testing")

	option = input()
	while option == 'r' or option == 'b':
		if option == 'r':
			neuron.train(nbEpochs)
		elif option == 'b':
			print('Best result achieved during last tests: ' + str(neuron.bestResult))
			#print(neuron.W1)
		print("Enter \n\"r\" for running tests (",nbEpochs, "epochs ) or \n\"b\" for the best accuracy result of last testing")
		option = input()
	
	#print(neuron.W1)
	print("Writing best weights output file")
	filename_weights='best_weights.npz'
	np.savez(filename_weights, name1=neuron.W1, name2=neuron.W2, name3=neuron.b1, name4=neuron.b2)
	data = np.load(filename_weights) # reading for future use
	print(data['name1'])
	print(data['name2'])
	print(data['name3'])
	print(data['name4'])


main()