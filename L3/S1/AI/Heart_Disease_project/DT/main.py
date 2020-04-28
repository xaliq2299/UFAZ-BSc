import pandas as pd
from DTLib import DT
import DTLib as DTLib

def main():
	pd.set_option('display.max_rows', None)
	data = pd.read_csv('heart_disease_dataset.csv', sep=';')
	data, edge_values = DTLib.transfer_values(data, [0, 3, 4, 7, 9], 8)
	data = data.sample(frac=1)
	train_length = int(len(data)*0.5)
	root = DT(None)
	print('len(data.columns)-1='+str(len(data.columns)-1))
	root = DTLib.decision_tree(root, data.iloc[:train_length, :], [], 1, len(data.columns)-1)
	correct = 0
	for i in range(len(data)-train_length):
		if DTLib.find_result(data.iloc[train_length+i, :], root):
			correct += 1
	print(str((correct/(len(data)-train_length))*100))







main()
