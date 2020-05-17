/*@
requires \valid(t+(0..n-1)) && n > 0;
ensures \forall integer i; 0<=i<n ==> \result <= t[i];
ensures \exists integer i; 0<=i<n && t[i] == \result;
*/
int min(int t[], int n) {
	int res = t[0];
	/*@
	loop invariant 1 <= i <= n;
	loop invariant \forall integer j; 0 <= j < i ==> res <= t[j];
	loop invariant \exists integer j; 0 <= j < i && res == t[j];
	loop variant n - i;
	*/
	for (int i = 1; i < n; i++)
		if (t[i] < res) res = t[i];
	return res;
}
