#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include "test.h"
#include "Stack.h"

using std::string;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::out_of_range;

typedef std::size_t size_type;
void test_empty_stack()
{
	stack<char> mystack;
	assert_equal(true, mystack.isEmpty());
	mystack.push('a');
	assert_equal((size_type)1, mystack.size());
	assert_equal('a', mystack.top());
	assert_equal(false, mystack.isEmpty());

	stack<int> stack1;
	assert_equal(true, stack1.isEmpty());
	stack1.push(65);
	assert_equal((size_type)1, stack1.size());
	assert_equal(65, stack1.top());
	assert_equal(false, stack1.isEmpty());
}

void test_push_pop()
{
	stack<char> mystack;
	mystack.push('a');
	mystack.push('b');
	assert_equal('b', mystack.pop());
	mystack.push('c');
	mystack.push('d');
	assert_equal((size_type)3, mystack.size());
	char item = mystack.top();
	test_('d' == item);
	mystack.pop();
	item = mystack.top();
	test_('c' == item);
	mystack.pop();
	mystack.pop();
	throw_(mystack.pop(), out_of_range);

}

void test_copy_constructor()
{
	stack<char> mystack;
	mystack.push('a');
	mystack.push('b');
	mystack.push('c');

	stack<char> stack1(mystack);
	stack1.pop();
	assert_equal((size_t)3, mystack.size());
	assert_equal((size_t)2, stack1.size());
	assert_equal('b', stack1.top());
}
void test_size()
{
	//tested other places
}
void test_op_equals()
{
	stack<char> mystack;
	mystack.push('a');
	mystack.push('b');
	mystack.push('c');

	stack<char> stack1 = mystack;
	stack1.pop();
	assert_equal((size_t)3, mystack.size());
	assert_equal((size_t)2, stack1.size());
	assert_equal('b', stack1.top());
	assert_equal('c', mystack.top());
}



void test_infix_to_postfix(char* fileName)
{

}

int main(int argc, char *argv[])
{
	test_empty_stack();
	test_push_pop();
	test_copy_constructor();
	test_size();
	test_op_equals();
	test_infix_to_postfix("tests.txt");
	report_();
	std::cin.ignore();
	return 0;
}