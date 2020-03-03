#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

int setup(void)  { return 0; }
int teardown(void) { return 0; }


CU_pSuite add_suite(const char* msg)
{
	CU_pSuite s = CU_add_suite(msg, setup, teardown);
	if (s == NULL)
	{
		printf("Error in add_suite %s ,%s\n",msg,CU_get_error_msg());
		CU_cleanup_registry();
		exit(1);
	}
	return s;
}


CU_pTest add_test(CU_pSuite s, const char* msg,  CU_TestFunc test_func)
{
	CU_pTest t = CU_add_test(s,msg,test_func);
	if (t == NULL)
	{
		printf("Error in add_test %s ,%s\n",msg,CU_get_error_msg());
		CU_cleanup_registry();
		exit(1);
	}
	return t;
}


