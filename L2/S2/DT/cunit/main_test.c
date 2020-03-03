#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../include/add.h"
#include "../include/divide.h"

int setup(){ return 0; }
int teardown(){ return 0; }

void test_add(){
	double x=5, y=7;
	CU_ASSERT_DOUBLE_EQUAL(add(x,y), 12, 0.00001);
}

void test_divide(){
	double x=6, y=2;
	CU_ASSERT_DOUBLE_EQUAL(divide(x,y), 3, 0.00001);
}


int main(){
	if(CU_initialize_registry() != CUE_SUCCESS){
		CU_get_error_msg();
		exit(1);
	}
	CU_pSuite s = CU_add_suite("operations", setup, teardown);
	CU_add_test(s,"test-add",test_add);
	CU_add_test(s,"test-divide",test_divide);

	CU_basic_run_tests();
	CU_basic_show_failures(CU_get_failure_list());

	return CU_get_number_of_failures();
}