/*@ requires n>0 && \valid(a+(0..n-1));
    behavior success:
      assumes \forall integer i; 0<=i<n-1 ==> a[i]<=a[i+1];
      ensures \result==1;
    behavior failure:
      assumes \exists integer i; 0<=i<n-1 && a[i]>a[i+1];
      ensures \result==0;
*/
int isIncreasing(int a[], int n){
  /*@ loop invariant 0<=i<=n-1;
      loop invariant \forall integer j; 0<=j<i ==> a[j]<=a[j+1];
      loop variant n-i;  
  */
  for(int i=0;i<n-1;i++){
    if(a[i]>a[i+1]) return 0;
  }
  return 1;
}