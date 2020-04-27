/*@
requires 0 <= n <= 1000;
ensures 2*\result == n*(n-1);
*/

int sum(int n){
	int sum=0;
	/*@
	loop invariant 0<=i<=n;
	loop invariant 2*sum == i*(i-1);
	loop variant n-i;
	*/
	for (int i=0;i<n;i++)
		sum += i;
	return sum;
}