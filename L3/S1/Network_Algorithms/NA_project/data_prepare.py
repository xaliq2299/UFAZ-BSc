import pandas as pd
import random
from tqdm import tqdm # used for observing process


def compute_airtime(data):
	'''
	as each instance of time is written as integer
	we assume that 2 last digit represent minutes 
	and 1 or 2 first digits represent hours
	'''
	for i in tqdm(range(len(data['DepTime']))):
		arr_h = int((data.loc[i, 'ArrTime'])/100)
		arr_m = int((data.loc[i, 'ArrTime'])%100)
		dep_h =	int((data.loc[i, 'DepTime'])/100)
		dep_m = int((data.loc[i, 'DepTime'])%100)
		air_h = (arr_h - dep_h)
		air_m = (arr_m - dep_m)
		if air_h < 0:
			air_h += 24
		if air_m < 0:
			air_m += 60
			air_h -= 1
		data.loc[i, 'AirTime'] = (air_h*60 + air_m)
	return data


#################################################################################
'''
read airports.csv into flights dataframe 
delete column we don't need : 'DepTime', 'ArrTime', 'DayOfWeek'
rename 'CRSDepTime', 'CRSArrTime' for easy usage
add 2 more column which we generate randomly 
next we check in which column we have 'None' or 'Nan' values and print it
compute air time for each flight
save data in data.csv file
'''
flights = pd.read_csv('airports.csv') 
del flights['DepTime']
del flights['ArrTime']
del flights['DayOfWeek']
flights.rename(columns={'CRSDepTime': 'DepTime', 'CRSArrTime': 'ArrTime'}, inplace=True)
#################################################################################
flights['Price'] = None
flights['Weather'] = None
for i in tqdm(range(len(flights['Price']))):
	flights.loc[i, 'Price'] = random.uniform(50, 2000)
	flights.loc[i, 'Weather'] = random.randint(0, 1)
#################################################################################
for i in list(flights.columns):
	if flights[i].isnull().any():
		print(i)
flights = compute_airtime(flights)
#################################################################################
flights.to_csv('data.csv', index=False)
