def func(string):
  myDict={}
  alphabet='abcdefghijklmnopqrstuvwxyz'
  for k in alphabet:
    myDict[k]=0
  for k in string:
    if k in myDict.keys():
      myDict[k] = 1
  return myDict

print(func('python is beautiful'))