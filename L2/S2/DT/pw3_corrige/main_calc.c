#include "polish.h"



int main()
{
  Stack pol = NewStack(256);

  char str[256];
  do
  {
  	scanf("%s",str);
  	NumOp no = String2NumOp(str);
	pushBack(&pol,no);
  }while (str[0] != '=');
  popBack(&pol); // remove =

  printf("%lf\n",front_eval_expression(&pol));
  return 0;
}

