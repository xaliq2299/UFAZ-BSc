/*@
  requires \valid(t+(0..n-1)) && \valid(s+(0..n-1)) && \valid(r+(0..n-1)) && n>0;
  requires \forall integer i; 0<=i<n ==> -10000<=t[i]<=10000;
  requires \forall integer i; 0<=i<n ==> -10000<=s[i]<=10000;
  ensures \forall integer i; 0<=i<n ==> r[i]==t[i]+s[i];
*/

void sum(int t[], int s[], int r[], int n){
  /*@
    loop invariant 0<=i<=n;
    loop invariant \forall integer j; 0<=j<i ==> r[j]==t[j]+s[j];
    loop variant n-i;
  */
  for(int i=0;i<n;i++){
    r[i]=t[i]+s[i];
  }
}


