/*@ requires n>0 && \valid(s+(0..n-1));
    ensures \forall integer i; 0<=i<n ==> s[i]==val;
*/
void fill(int s[], int val, int n){
  /*@ loop invariant 0<=i<=n;
      loop invariant \forall integer j; 0<=j<i ==> s[j]==val;
      loop variant n-i;
  */
  for(int i=0;i<n;i++){
    s[i]=val;
  }
}