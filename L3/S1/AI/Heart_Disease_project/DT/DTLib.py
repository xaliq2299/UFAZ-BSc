import numpy as np

class DT(object):
	value = None
	based_on_which_col = None
	leafs = None
	answer = None
	"""docstring for DT"""
	def __init__(self, value):
		self.value = value
		


def class_entropy(data):
	res = 0 
	for i in np.unique(data.iloc[:, [-1]]):
		temp = len(data.loc[data.iloc[:, -1] == i])
		res += temp/len(data)*(np.log(temp/len(data))/np.log(2))
	return -res


def entropy(data):
	res = class_entropy(data.iloc[:, [-1]])
	for i in np.unique(data.iloc[:, 0]):
		data_temp = data.loc[data.iloc[:, 0] == i]
		res -= len(data_temp)/len(data)*class_entropy(data_temp)
	return res


# def disc_power(data):
# 	data_temp = data.iloc[:, [0, -1]]
# 	maxDisc = entropy(data_temp)
# 	maxIndex = 0
# 	for i in range(1, len(data.columns)-1):
# 		data_temp = data.iloc[:, [i, -1]]
# 		temp = entropy(data_temp)
# 		if temp > maxDisc:
# 			maxDisc = temp
# 			maxIndex = i
# 	return maxIndex

def disc_power(data):
	powers = {}
	for i in range(len(data.columns)-1):
		data_temp = data.iloc[:, [i, -1]]
		powers[i] = entropy(data_temp)
	return powers


def transfer_values(data, columns_to_transfer, k):
	checkpoints = []
	for i in range(1, k+1):
		checkpoints.append(int((len(data)-1)/k*i))
	edges_values = {}
	for i in columns_to_transfer:
		data.iloc[:,i]=sorted(data.iloc[:, i]) 
		edges_values[i] = []
		for j in checkpoints:
			edges_values[i].append(data.iloc[j, i])
		for j in range(len(data)):
			for q in range(k):
				if data.iloc[j, i] <= edges_values[i][q]:
					data.iloc[j, i] = q
					break
	return data, edges_values

def max_occcurence(data):
	value = None
	max_length = 0
	for i in np.unique(data.iloc[:, -1]):
		temp = len(data.loc[data.iloc[:, -1] == i])
		if temp > max_length:
			value = i
			max_length = temp			
	return value


# def decision_tree(root, data):
# 	# print(str(len(np.unique(data.iloc[:, -1]))))
# 	# print(str(len(data.columns)))
# 	if (len(np.unique(data.iloc[:, -1])) == 1) or (len(data.columns) == 2):
# 		root.based_on_which_col = -1
# 		root.leafs.append(DT(max_occcurence(data.iloc[:, [-1]])))
# 		return root
# 	index = disc_power(data)
# 	root.based_on_which_col = index
# 	# print(str(list(np.unique(data.iloc[:, index]))))
# 	for i in list(np.unique(data.iloc[:, index])):
# 		# data_temp = data.loc[data.iloc[:, 0] == i]
# 		root.leafs.append(DT(i))
# 		root.leafs[len(root.leafs)-1] = decision_tree(root.leafs[len(root.leafs)-1], data.loc[data.iloc[:, index] == i])
# 	return root

def get_dict_index(dictionary, value):
	return list(dictionary.values()).index(value)

def decision_tree(root, data, visited, level, maxDepth):
	# print('enter, level '+str(level))
	# print('visited '+str(visited) + ' length '+str(len(visited)))
	if (len(np.unique(data.iloc[:, -1])) == 1) or level == maxDepth:
		root.based_on_which_col = -1
		root.leafs = []
		temp = DT(max_occcurence(data.iloc[:, [-1]]))
		root.leafs.append(DT(max_occcurence(data.iloc[:, [len(data.columns)-1]])))
		# print('return with root.value '+str(root.value))
		# print(str(len(root.leafs)))
		# print('based_on_which_col '+str(root.based_on_which_col))
		# print('final value '+str(root.leafs[0].value)+'\n')
		return root
	index = 0

	powers = disc_power(data)
	for i in sorted(powers.values(), reverse=True):
		# print(str(get_dict_index(powers, i)))
		index = get_dict_index(powers, i)
		# print('for loop '+str(index))
		if (index not in visited):
			# print('index is not in  visited')
			break
	if index in visited:
		root.based_on_which_col = -1
		root.leafs = []
		temp = DT(max_occcurence(data.iloc[:, [-1]]))
		root.leafs.append(temp)
		return root
	# print('index='+str(index))
	visited.append(index)
	root.based_on_which_col = index
	# print('root.value '+str(root.value))
	# print(str(list(np.unique(data.iloc[:, index]))))
	root.leafs = []
	for i in list(np.unique(data.iloc[:, index])):
		# print('for')
		# root.leafs.append(DT(i))
		temp = DT(i)
		# print('unique='+str(i))
		# print(str(data.loc[data.iloc[:, index] == i])+'\n')
		temp_visited = visited.copy()
		# temp = decision_tree(temp, data.loc[data.iloc[:, index] == i], temp_visited, level+1)
		root.leafs.append(decision_tree(temp, data.loc[data.iloc[:, index] == i], temp_visited, level+1, maxDepth))
		# root.leafs[len(root.leafs)-1] = decision_tree(root.leafs[len(root.leafs)-1], data.loc[data.iloc[:, index] == i], visited.copy(), level+1)
	# print('root.leafs len '+str(len(root.leafs)))
	return root



def print_tree(root):
	print('\n\n')
	if root.based_on_which_col == -1:
		print('final value '+str(root.leafs[0].value))
		return
	for i in root.leafs:
		print(str(i.value))
	print()
	for i in root.leafs:
		print(str(i.value))
		print_tree(i)
	print('\n\n')



def find_result(instance, root):
	while root.based_on_which_col != -1:
		for i in range(len(root.leafs)):
			# print('root.leafs[i].value='+str(root.leafs[i].value))
			# print('instance[root.based_on_which_col]='+str(instance[root.based_on_which_col]))
			if root.leafs[i].value == instance[root.based_on_which_col]:
				break
		root = root.leafs[i]
	if root.leafs[0].value == instance[-1]:
		return 1
	else:
		return 0