/*@
requires 0 <= n <= 1000;
ensures \result == n * n;
assigns \nothing;
*/
int sumOdd(int n){
  int res=0;
  int i=0;
  /*@
    loop invariant 0<=i<=n;
    loop invariant res == i*i;
    loop variant n-i;
  */
  while(i<n){
    res+=i*2+1;
    i++;
  }
  return res;
}

