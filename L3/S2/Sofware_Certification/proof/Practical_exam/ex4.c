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