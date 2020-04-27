/*@
requires \valid(t+(0..n-1)) && n>0;
ensures (\forall integer i; 0<=i<n && t[i] == 0) ==> \result == 1;
ensures (\exists integer i; 0<=i<n && t[i] != 0) ==> \result == 0;
*/

int all_zeros(int t[], int n){
	/*@
		loop invariant 0<=i<=n;
		loop invariant \forall integer j; 0 <= j < i ==> t[j] == 0;
		loop variant n-i;
	*/
	for(int i=0;i<n;i++){
		if(t[i] != 0)
			return 0;
	}
	return 1;
}
