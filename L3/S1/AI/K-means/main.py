import numpy as np
import random as rnd
import csv

class Cluster:
	def __init__(self): # constructor
		self.set=[]
		self.centroid=[0,0,0,0] # decide about it

	def findCentroid(self): # method to find center of cluster
		self.centroid=[0,0,0,0]
		for i in range(4):
			for j in range(len(self.set)):
				self.centroid[i] += float(self.set[j][i])
		for i in range(4):
			if len(self.set) != 0:
				self.centroid[i] /= len(self.set)
		return self.centroid

	def printSummary(self):
		print("Centroid of cluster: ", self.findCentroid())
		print("Length of cluster: ", len(self.set) )
		#print(clusters[i].set)

def distance(a,b): # a function to calculate Euclidian distance between a and b 
	#print(a,b)
	if len(a) != len(b):
		return None
	dist=0
	for i in range(len(a)):
		dist += (float(a[i])-float(b[i]))**2
	return dist

def stillChanges(clusters): # detects whether clusters still change
	flag=False
	# if empty sets
	if len(clusters[0].set) == 0 or len(clusters[1].set) == 0 or len(clusters[2].set) == 0:
		flag=True
		return flag
	
	for i in range(len(clusters)):
		for j in range(len(clusters[i].set)):
			distances=np.zeros(3) # precise the place for np array of 0s
			for k in range(len(clusters)):
				#print(clusters[i].set[j], clusters[k].centroid)
				distances[k]=distance(clusters[i].set[j],clusters[k].centroid)
			
			#print(distances)
			min = distances.argmin() # closest cluster
			if min != i:
				flag=True
				return flag
	return flag

def findCluster(clusters,item): # find which cluster given item belongs to
	for i in range(len(clusters)):
		for j in range(len(clusters[i].set)):
			if clusters[i].set[j] == item:
				return i
	return -1

def read_file(filename,nClusters): # reading file, getting and returning data together with clusters
	# opening file and reading data
	data=[]
	try:
		file=open(filename, 'rt')
	except FileNotFoundError:
		print("[!] Provided file does not exist.")
		exit(0)

	line=file.readline()
	while line != "\n":
		#print(line)
		parse=line.split(',')
		#print(parse)
		data.append(parse[:4]) # taking first 4 columns since last one (name of flour) is not needed
		line=file.readline()
	#print(data)
	file.close()

	# Starting job with clusters
	clusters=[]
	for i in range(nClusters):
		clusters.append(Cluster())

	# Step needed: appending irisData elements to clusters beforehand
	for i in range(nClusters):
		start=i*len(data)//nClusters
		end = start+len(data)//nClusters
		for j in range(start,end):
			clusters[i].set.append(data[j][:4])

	return (data,clusters)

def main():
	irisData=[]
	k=3 # number of clusters
	k=int(input("Enter number of clusters: "))
	irisData,clusters=read_file('iris_text.data',k)

	# Algorithm starts here
	# Step 1: Cluster initialisation
	for i in range(k):
		index=rnd.randint(0,len(irisData)-1)
		clusters[i].centroid=irisData[index]

	# Step 2: Assigning datapoint to clusters
	steps=0
	LIMIT=k*5+1 # Setting a Maximal Number of iterations
	while( steps<LIMIT ): #stillChanges(clusters)
		#print("Step ", steps)
		# Euclidian distance with respect to each centroid
		for count in range(len(irisData)):
			distances=np.zeros(k) # [0, 0, 0]
			for d in range(k):
				distances[d]=distance(irisData[count],clusters[d].centroid)
			#print(distances)
			min = distances.argmin() # closest cluster
			current = findCluster(clusters,irisData[count])
			if min != current and current != -1: # if doesn't belong to the same cluster
				#print(i,j,min)
				clusters[current].set.remove(irisData[count])
				clusters[min].set.append(irisData[count])
			
		# Step 3: Updating clusters center
		for i in range(k):
			clusters[i].findCentroid()	
		# Following 2 lines of code is to see if clusters still change
		#for i in range(k):
			#print( len(clusters[i].set) )
			
		steps += 1

	# Summary
	for i in range(k):
		print("Cluster", i+1, ":")
		clusters[i].printSummary()
		print("")

	# Exporting clusters in a csv file
	csvFile=open("clusters.csv","w+")
	for i in range(k):
		for j in range(len(clusters[i].set)):
			csvFile.write(str(i)+",") # wir
			writer = csv.writer(csvFile)
			row=clusters[i].set[j] # TODO
			#row[0]=i
			writer.writerow(row)

	csvFile.close()

if __name__== "__main__" :
	main()