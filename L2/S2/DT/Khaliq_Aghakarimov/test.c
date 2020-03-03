#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "string/string.h"

int setup(){ return 0; }
int teardown(){ return 0; }

void test_length1(){
	char *str="hello";
	CU_ASSERT_EQUAL(length(str), 5);
}

void test_length2(){
	char *str="";
	CU_ASSERT_EQUAL(length(str), 0);
}

void test_compare1(){
	CU_ASSERT_EQUAL(compare("aba", "aba"), 0);
	CU_ASSERT_EQUAL(compare("hello", "hello"), 0);
	CU_ASSERT_EQUAL(compare(" ", " "), 0);
}

void test_compare2(){
	CU_ASSERT_EQUAL(compare("ours", "yours"), 1);
	CU_ASSERT_EQUAL(compare("yours", "ours"), 1);
	CU_ASSERT_EQUAL(compare("someone", "somebody"), 1);		
	CU_ASSERT_EQUAL(compare("someone", " "), 1);		
}

void test_palindrome1(){
	CU_ASSERT_EQUAL(palindrome("ababa"),1);
	CU_ASSERT_EQUAL(palindrome("kicik"),1);
}

void test_palindrome2(){
	CU_ASSERT_EQUAL(palindrome("aaabbb"),0);
}


int main(){
	if(CU_initialize_registry() != CUE_SUCCESS){
		CU_get_error_msg();
		exit(1);
	}
	CU_pSuite length = CU_add_suite("length", setup, teardown);
	CU_pSuite compare = CU_add_suite("compare", setup, teardown);
	CU_pSuite palindrome = CU_add_suite("palindrome", setup, teardown);

	CU_add_test(length,"test-length1",test_length1);
	CU_add_test(length,"test-length1",test_length2);
	CU_add_test(compare,"test-compare1",test_compare1);
	CU_add_test(compare,"test-compare2",test_compare2);
	CU_add_test(palindrome,"test-palindrome1",test_palindrome1);
	CU_add_test(palindrome,"test-palindrome2",test_palindrome2);

	CU_basic_run_tests();
	CU_basic_show_failures(CU_get_failure_list());

	return CU_get_number_of_failures();
}