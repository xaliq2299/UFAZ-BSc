/*@
	behavior a_less:
		assumes a<b;
		ensures \result == a;
	behavior b_less:
		assumes a>=b;
		ensures \result == b;
*/
int min(int a, int b){
	if(a<b)
		return a;
	else
		return b;
}