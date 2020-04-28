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
	print("Enter \n\"r\" for running tests (",nbEpochs, "epochs ) or \n\"b\" for the best accuracy result of last testing or \n\"s\" for the saving best accuracy result or \n\"l\" for the loading best accuracy result")

	option = input()
	while option == 'r' or option == 'b' or option == 's' or option == 'l':
		if option == 'r':
			neuron.train(nbEpochs)
		elif option == 'b':
			print('Best result achieved during last tests: ' + str(neuron.bestResult))
		elif option == 's':
			neuron.dataSave()
		elif option == 'l':
			neuron.dataLoad()
		print("Enter \n\"r\" for running tests (",nbEpochs, "epochs ) or \n\"b\" for the best accuracy result of last testing or \n\"s\" for the saving best accuracy result or \n\"l\" for the loading best accuracy result or \nelse to quit")
		option = input()


main()