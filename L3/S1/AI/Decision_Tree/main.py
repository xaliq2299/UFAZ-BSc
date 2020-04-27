import math
# from util import Tree

def entropyData(data,nGroup):
	nIris=len(data)
	nInstances=nIris/nGroup
	entropy=0.0
	for k in range(0,nGroup):
		tmp=nInstances/nIris
		if tmp > 0:
			entropy -= tmp*math.log(tmp,2)
	return entropy

def entropyGroup(data):
	nSpecies=[0,0,0]
	H_g=0
	for item in data:
		#print(item)
		if item[4] == "Iris-virginica\n":
			nSpecies[0]+=1
		elif item[4] == "Iris-setosa\n":
			nSpecies[1]+=1
		elif item[4] == "Iris-versicolor\n":
			nSpecies[2]+=1
		else:
			print("problem")
	print("nSpecies1 =",nSpecies[0],", nSpecies2=",nSpecies[1], ", nSpecies3=",nSpecies[2])
	for i in range(0,3):
		tmp=nSpecies[i]/len(data)
		if tmp != 0:
			H_g -= tmp*math.log(tmp,2)
	return H_g

def discriminativePower(data,H,attr,nGroup):
	#print("==================================")
	#print("Attribute ", attr)
	disc=0.0
	disc+=H
	nIris=len(data)
	nElementsGroup=nIris//nGroup
	#print(data)
	# print("#Iris =", nIris)
	# print("#G =", nGroup)
	# print("#g =", nElementsGroup)
	irisDataSorted=sorted(data,key=lambda x: (x[attr]))
	#print(irisDataSorted)
	group1=irisDataSorted[0:nElementsGroup]
	group2=irisDataSorted[nElementsGroup:2*nElementsGroup]
	group3=irisDataSorted[nElementsGroup*2:3*nElementsGroup]
	# print(group1)
	H_g=[0,0,0]
	H_g[0]=entropyGroup(group1)
	H_g[1]=entropyGroup(group2)
	H_g[2]=entropyGroup(group3)
	# print("Entropies: ", H_g[0], H_g[1], H_g[2])
	
	for g in range(0,G):
		disc -= nElementsGroup/nIris*H_g[g] # info. gain

	return disc


irisData=[]
G=3 # number of groups

file=open("iris_text.data", 'rt')
line=file.readline()
while line != "\n":
	# print(line)
	parse=line.split(',')
	# print(parse)
	irisData.append(parse)
	line=file.readline()

# print(irisData)
H_Iris=entropyData(irisData,G)
print("entropy of data set =", H_Iris, "\n")


iAttr=0
disc=discriminativePower(irisData,H_Iris,iAttr,G)
print("Discriminative power of attribute ", iAttr, ":", disc)
big=disc
for iAttr in [1,2,3]:
	disc=discriminativePower(irisData,H_Iris,iAttr,G)
	print("Discriminative power of attribute ", iAttr, ":", disc)
	if disc > big:
		big=disc

print("disc biggest =", disc, "\n")


# root = Tree()
# root.data = "SL"
# root.left = Tree()
# root.left.data = "short"
# root.middle = Tree()
# root.middle.data = "medium"
# root.right = Tree()
# root.right.data = "right"

# root.print()
