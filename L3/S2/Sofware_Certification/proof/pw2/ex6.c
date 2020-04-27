/*@ requires \valid(t+(0..tt-1)) && tt>0;
    requires \valid(s+(0..ts-1)) && ts>0;
    requires \valid(r+(0..tt+ts));
    requires 0<tt<100;
    requires 0<ts<100;
    ensures \forall integer i; 0<=i<tt ==> r[i]==t[i];
    ensures \forall integer j; 0<=j<ts ==> r[j+tt]==s[j];
*/
void concat(int t[], int tt, int s[], int ts, int r[]){
  /*@ loop invariant 0<=i<=tt;
      loop invariant \forall integer j; 0<=j<i ==> r[j]==t[j];
      loop variant tt-i;
  */
  for(int i=0;i<tt;i++){
    r[i]=t[i];
  }
  /*@ loop invariant 0<=i<=ts;
      loop invariant \forall integer j; 0<=j<tt ==> r[j]==t[j];
      loop invariant \forall integer j; 0<=j<i ==> r[j+tt]==s[j];
      loop variant ts-i;
  */
  for(int i=0;i<ts;i++){
    r[i+tt]=s[i];
  }
}