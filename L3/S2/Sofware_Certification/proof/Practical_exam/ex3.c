/*@
  requires \valid(t+(0..taille-1)) && taille>0;
  ensures (\forall integer i; 0<=i<taille-1 ==> t[i]<=t[i+1]) ==> \result==1;
  ensures (\exists integer i; 0<=i<taille-1 && t[i]>t[i+1])  ==> \result==0;
*/

int increasing(int t[], int taille){
  /*@
    loop invariant 0<=i<=taille-1;
    loop invariant \forall integer j; 0<=j<i ==> t[j]<=t[j+1];
    loop variant taille-i-1;
  */
  for(int i=0;i<taille-1;i++){
    if(t[i]>t[i+1]) return 0;
  }
  return 1;  
}