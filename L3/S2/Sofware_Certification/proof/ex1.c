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
