/*@
	requires \valid(t+(0..n-1)) && n>0;
	ensures (\exists integer i; 0<=i<n && t[i] == x) ==> -1<=\result<n;
	ensures (\forall integer i; 0<=i<n ==> t[i] != x) ==> \result == -1;
*/

int index(int t[], int n, int x){
	/*@
	loop invariant 0<=i<=n;
	loop invariant \forall integer j; 0<=j<i ==> t[j] != x;
	loop variant n-i;
	*/
	for(int i=0;i<n;i++){
		if(t[i] == x)
			return i;
	}
	return -1;
}
