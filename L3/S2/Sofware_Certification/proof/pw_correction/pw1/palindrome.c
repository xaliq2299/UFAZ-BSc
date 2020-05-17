/*@ requires n>0 && \valid(s+(0..n-1));
    behavior success:
    assumes \forall integer i; 0<=i<n ==> s[i]==s[n-i-1];
    ensures \result == 1;
    behavior failure:
    assumes \exists integer i; 0<=i<n && s[i]!=s[n-i-1];
    ensures \result == 0;
*/
int isPalindrome(int s[], int n){
  /*@ loop invariant 0 <=i<=n;
      loop invariant \forall integer j; 0<=j<i ==> s[j]==s[n-j-1];
      loop variant n-i;
  */
  for(int i=0;i<n;i++){
    if(s[i]!=s[n-i-1]) return 0;
  }
  return 1;
}