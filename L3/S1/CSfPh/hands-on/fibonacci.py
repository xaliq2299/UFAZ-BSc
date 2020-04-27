
#Initialization
u0=1            
u1=1
count=0

# Print the two first terms of the sequence (u0 and u1)
print(u0)
print(u1)

while(count<=18):
  
  # Calculate the new term (result), then prepare the next iteration by 
  # shifting u1 into u0 and the result into u1. 
  result=u1+u0
  u0=u1
  u1=result
  count+=1

  # Print the current value of the result
  print(result)