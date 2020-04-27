/*@
	requires \valid(t+(0..n-1)) && n>0;
	ensures (\forall integer i; 0<=i<n ==> t[i] == t[n-i-1]) ==> \result==1; // look at this it is ==> !!!
	ensures (\exists integer i; 0<=i<n && t[i] != t[n-i-1]) ==> \result==0;
*/

int palindrome(int t[], int n){
	/*@
		loop invariant 0<=i<=n;
		loop invariant \forall integer j; 0<=j<i ==> t[j] == t[n - j - 1];
		loop variant n/2-i;
	*/
	for (int i = 0; i <= n / 2; i++) {
        if (t[i] != t[n - i - 1])
            return 0;
    }
    return 1;
}