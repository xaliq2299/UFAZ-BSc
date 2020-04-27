def func(string):
  myDict={}
  for i in string:
    if i!=' ':
      if i in myDict.keys():
        myDict[i] = myDict[i] + 1
      else:
        myDict[i] = 1
  return myDict

print(func('python is beautiful'))