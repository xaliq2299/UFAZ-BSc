/*@ requires \valid(t+(0..n-1)) && n>0;
    behavior success:
    assumes \exists integer i; 0<=i<n && t[i]==val;
    ensures 0<=\result<n;
    behavior failure:
    assumes \forall integer i; 0<=i<n ==> t[i]!=val;
    ensures \result==-1;
*/
int index(int t[], int val, int n){
  /*@ loop invariant 0<=i<=n;
      loop invariant \forall integer j; 0<=j<i ==> t[j]!=val;
      loop variant n-i;
  */
  for(int i=0;i<n;i++){
    if(t[i]==val) return i;
  }
  return -1;
}