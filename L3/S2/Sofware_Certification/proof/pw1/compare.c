/*@
	requires \valid(t1+(0..n-1)) && \valid(t2+(0..n-1)) && n>0;
	ensures (\forall integer i; 0<=i<n ==> t1[i] == t2[i]) ==> \result==1; // look at this it is ==> !!!
	ensures (\exists integer i; 0<=i<n && t1[i] != t2[i]) ==> \result==0;
*/

int compare(int t1[], int t2[], int n){
	/*@
		loop invariant 0<=i<=n;
		loop invariant \forall integer j; 0<=j<i ==> t1[j] == t2[j];
		loop variant n-i;
	*/
	for(int i=0;i<n;i++)
		if(t1[i] != t2[i])
			return 0;
	return 1;
}