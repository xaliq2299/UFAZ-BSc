/*@
requires \valid(p);
requires \valid(q);
assigns *p;
assigns *q;
ensures *p == \old(*q);
ensures *q == \old(*p);
*/
void swap(int* p, int* q){
	int tmp = *p;
	*p=*q;
	*q=tmp;
	return;
}