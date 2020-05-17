/*@ requires \valid(p) && \valid(q);
    requires -10000<*p<10000 && -10000<*q<10000;
    assigns *p;
    assigns *q;
    ensures *p==\old(*q);
    ensures *q==\old(*p);
*/
void swap(int *p, int *q){
  int sum=*p + *q;
  *p=sum-*p;
  *q=sum-*p;
}