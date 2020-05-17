/*@
	behavior first_case:
		behavior first1_case:
			assumes num1>num2;
			assumes num1>num3;
			ensures \result == num1;
		

		behavior first2_case:
			assumes num1>num2;	
			assumes num1<=num3;
			ensures \result == num3;
	
	behavior second_case:
		behavior second1_case:
			assumes num1<=num2;
			assumes num2>num3;
			ensures \result == num2;
		behavior second2_case:
			assumes num1<=num2;
			assumes num2<=num3;
			ensures \result == num3;
*/

int max3(int num1, int num2, int num3){
    if(num1 > num2){
        if(num1 > num3)
            return num1;
        else
            return num3;
    }
    else
    {
        if(num2 > num3)
            return num2;
        else
            return num3;
    }
}






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



/*@
  requires \valid(t+(0..taille-1)) && taille>0;
  ensures (\forall integer i; 0<=i<taille-1 ==> t[i]<=t[i+1]) ==> \result==1;
  ensures (\exists integer i; 0<=i<taille-1 && t[i]>t[i+1])  ==> \result==0;
*/

int increasing(int t[], int taille){
  /*@
    loop invariant 0<=i<=taille-1;
    loop invariant \forall integer j; 0<=j<i ==> t[j]<=t[j+1];
    loop variant taille-i-1;
  */
  for(int i=0;i<taille-1;i++){
    if(t[i]>t[i+1]) return 0;
  }
  return 1;  
}




/*@
    requires \valid(t+(0..taille-1)) && taille>0;
    
*/

int monotonic(int t[], int taille) {
  /*@
    loop invariant 1<=i<=taille;
    loop invariant \forall integer j; 1<=j<i ==> t[j]>=t[j-1];
    loop variant taille-i;
  */        
        for (int i = 1; i < taille; i++) {
            if (t[i] < t[i - 1])
                return 0;
        }
        return 1;
  /*@
    loop invariant 1<=i<=taille;
    loop invariant \forall integer j; 1<=j<i ==> t[j]<=t[j-1];
    loop variant taille-i;
  */        
    
        for (int i = 1; i < taille; i++) {
            if (t[i] > t[i - 1]) 
                return 0;
        }
        return 1;
}