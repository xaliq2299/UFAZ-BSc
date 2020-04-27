def func(readfileName,writefileName):
        
  #Open the text file, read the text and close it
  FID=open(readfileName,'rt')
  lyrics=FID.read()
  FID.close()
  
  #Calculate the number of each letter
  myDict={}
  alphabet='abcdefghijklmnopqrstuvwxyz'
  for k in alphabet:
    myDict[k]=0
  for k in lyrics:
    if k in myDict.keys():
      myDict[k] += 1
  
  #Save the result in a file
  FID=open(writefileName,'wt')  
  for k in alphabet:
    strToWrite = k + '\t' +str(myDict[k]) + '\n'
    FID.writelines(strToWrite)
  FID.close()

func('allYouNeedIsLove.txt','result.txt')