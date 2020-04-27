/*@ requires 0<x<=100 && 0<y<=100;
    ensures \result == x*y;
    ensures 0<\result<=10000;
*/


int mul(int x, int y){
  int mul=0;
  /*@
  	loop invariant 0<=i<=y;
  	loop invariant mul==x*i;
    loop variant y-i;
  */
  for(int i=0;i<y;i++)
    mul+=x;
  return mul;
}