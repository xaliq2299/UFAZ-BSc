/*@ requires n>0 && \valid(s+(0..n-1)) && \valid(t+(0..n-1));
    assigns s[0..n-1];
    ensures \forall integer i; 0<=i<n ==> s[i]==t[i];
*/
void copy1(int s[], int t[], int n) {
  /*@ loop invariant 0<=i<=n;
      loop invariant \forall integer j; 0<=j<i ==> s[j]==t[j];
      loop variant n-i;
  */
  for(int i=0;i<n;i++){
    s[i]=t[i];
  }
}