/*@
requires \valid(t+(0..n-1)) && n > 0;
ensures \forall integer i; 0<=i<n ==> t[\result] <= t[i];
ensures \exists integer i; 0<=i<n && i == \result;
ensures 0<=\result<n;
*/
int min(int t[], int n) {
	int index = 0;
	/*@
	loop invariant 0 <= i <= n;
	loop invariant 0<=index<n;
	loop invariant \forall integer j; 0<=j<i ==> t[index] <= t[j];
	loop invariant \exists integer j; 0 <= j < i && index == j;
	loop variant n - i;
	*/
	for (int i = 1; i < n; i++){
		if (t[i] < t[index])
			index=i;
	}
	return index;
}