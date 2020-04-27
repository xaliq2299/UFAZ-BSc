/*@
  requires \valid(a+(0..n-1)) && n>0;
  ensures (\forall integer i; 0<=i<n-1 ==> a[i]<=a[i+1]) ==> \result==1;
  ensures (\exists integer i; 0<=i<n-1 && a[i]>a[i+1])  ==> \result==0;
*/

int isIncreasing(int a[], int n){
  /*@
    loop invariant 0<=i<=n-1;
    loop invariant \forall integer j; 0<=j<i ==> a[j]<=a[j+1];
    loop variant n-i-1;
  */
  for(int i=0;i<n-1;i++){
    if(a[i]>a[i+1]) return 0;
  }
  return 1;  
}