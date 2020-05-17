/*@
	requires \valid(t+(0..taille-1)) && taille>0;
	ensures \forall integer i; 0<=i<taille ==> t[i] == 2*i;
*/

void doubled(int t[], int taille){
	/*@
		loop invariant 0<=i<=taille;
		loop invariant \forall integer j; 0<=j<i ==> t[j] == 2*j;
		loop variant taille-i;
	*/
	for (int i=0;i<taille;i++)
		t[i] = 2*i;
}