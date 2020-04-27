
# Main loop
for i in range(2,101):
  primeNumber=True
  
  # If the rest Euclidian division of i by at least one number between 2 and 
  # i-1 is 0, i has a divider which is nor 1 nor itself, thus, i is not prime
  for k in range(2,i):
    if(i%k==0):
      primeNumber=False

  # If after this loop primeNumber is still True, display u
  if primeNumber:
    print(i)