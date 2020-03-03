#include "polish.h"
#include "testing.h"


void test_string2NumOp()
{
	CU_ASSERT_EQUAL(String2NumOp("+").code, -'+');
	CU_ASSERT_EQUAL(String2NumOp("-").code, -'-');
	CU_ASSERT_EQUAL(String2NumOp("*").code, -'*');
	CU_ASSERT_EQUAL(String2NumOp("/").code, -'/');
	
	CU_ASSERT_DOUBLE_EQUAL(String2NumOp("0.251").value, 0.251, 0.0000001);

	double x = 1.0/3.0;
	char s[256];
	sprintf(s,"%lf",x);

	CU_ASSERT_DOUBLE_EQUAL(String2NumOp(s).value,x,0.0001);
	CU_ASSERT_DOUBLE_EQUAL(String2NumOp("0.0").value, 0.0, 0.0000001);
	CU_ASSERT_DOUBLE_EQUAL(String2NumOp("-99999999.99").value, -99999999.99, 0.0000001);
	CU_ASSERT_DOUBLE_EQUAL(String2NumOp("99999999.99").value, 99999999.99, 0.0000001);
}

void test_stack1()
{
	Stack s = NewStack(32);
	CU_ASSERT_TRUE(empty(&s));
	NumOp n;
	n.code = -1;
	pushBack(&s,n);
	NumOp m = back(&s);
	CU_ASSERT_EQUAL(m.code,n.code);
	CU_ASSERT_FALSE(empty(&s));
	popBack(&s);
	CU_ASSERT_TRUE(empty(&s));
}

void test_stack2()
{
	Stack s = NewStack(32);
	CU_ASSERT_TRUE(empty(&s));
	NumOp n;
	n.code = -1;
	pushBack(&s,n);
	NumOp m = front(&s);
	CU_ASSERT_EQUAL(m.code,n.code);
	CU_ASSERT_FALSE(empty(&s));
	popFront(&s);
	CU_ASSERT_TRUE(empty(&s));
}

void test_stack3()
{
	Stack s = NewStack(32);
	CU_ASSERT_TRUE(empty(&s));
	NumOp n;
	n.code = -1;
	pushFront(&s,n);
	NumOp m = back(&s);
	CU_ASSERT_EQUAL(m.code,n.code);
	CU_ASSERT_FALSE(empty(&s));
	popBack(&s);
	CU_ASSERT_TRUE(empty(&s));
}

void test_stack4()
{
	Stack s = NewStack(32);
	CU_ASSERT_TRUE(empty(&s));
	for(int i=0; i<10; ++i)
	{
		NumOp n;
		n.code = -i;
		pushBack(&s,n);
	}
	
	for(int i=0; i<10; ++i)
	{
		NumOp n;
		CU_ASSERT_EQUAL(front(&s).code,-i);
		popFront(&s);
	}
}

void test_polish1()
{
	Stack s = NewStack(32);
	pushBack(&s,String2NumOp("3"));
	pushBack(&s,String2NumOp("4"));
	pushBack(&s,String2NumOp("+"));
	CU_ASSERT_DOUBLE_EQUAL(front_eval_op(&s), 7.0, 0.00001);

	pushBack(&s,String2NumOp("3"));
	pushBack(&s,String2NumOp("4"));
	pushBack(&s,String2NumOp("*"));
	CU_ASSERT_DOUBLE_EQUAL(front_eval_op(&s), 12.0, 0.00001);

}

void test_polish2()
{
	Stack s = NewStack(32);
	pushBack(&s,String2NumOp("3"));
	pushBack(&s,String2NumOp("4"));
	pushBack(&s,String2NumOp("+"));
	pushBack(&s,String2NumOp("3"));
	pushBack(&s,String2NumOp("*"));
	pushBack(&s,String2NumOp("7"));
	pushBack(&s,String2NumOp("/"));
	CU_ASSERT_DOUBLE_EQUAL(front_eval_expression(&s), 3.0, 0.00001);
}

int main()
{
	if (CU_initialize_registry() != CUE_SUCCESS)
		return CU_get_error();

	CU_pSuite s1 = add_suite("conversion");
	add_test(s1,"test_string2NumOp", test_string2NumOp);
	add_test(s1,"test_stack1	", test_stack1);
	add_test(s1,"test_stack2", test_stack2);
	add_test(s1,"test_stack3", test_stack3);
	add_test(s1,"test_stack4", test_stack4);

	CU_pSuite s3 = add_suite("Polish");
	add_test(s3,"test_oper", test_polish1);
	add_test(s3,"test_expr", test_polish2);


	CU_basic_run_tests();
	CU_basic_show_failures(CU_get_failure_list());
	
	return CU_get_number_of_failures();
}
