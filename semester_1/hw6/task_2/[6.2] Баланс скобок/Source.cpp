#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

int result(Stack *stack, const string &s)
{
	bool result = 1;
	for (int i = 0; i < s.length(); ++i)
	{
		char c = s[i];
		if ((c == '[') || (c == '(') || (c == '{'))
		{
			push(stack, c);
		}
		else if (c == ']')
		{
			result = result && (pop(stack) == '[');
		}
		else if (c == ')')
		{
			result = result && (pop(stack) == '(');
		}
		else if (c == '}')
		{
			result = result && (pop(stack) == '{');
		}
	}
	result = result && isEmpty(stack);
	return result;
}

bool test1()
{
	auto stack = createStack();
	string s = "([hello])";
	int res = result(stack, s);
	deleteStack(stack);
	return res == 1;
}

bool test2()
{
	auto stack = createStack();
	string s = "([hello)";
	int res = result(stack, s);
	deleteStack(stack);
	return res == 0;
}

bool test3()
{
	auto stack = createStack();
	string s = "()[()]{()()[]}";
	int res = result(stack, s);
	deleteStack(stack);
	return res == 1;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	Stack *stack = createStack();
	string s = "";
	cout << "Test 1: " << test1() << endl;
	cout << "Test 2: " << test2() << endl;
	cout << "Test 3: " << test3() << endl;
	cout << "������� ������:" << endl;
	getline(cin, s);
	cout << "���������� ������: " << result(stack, s) << endl;
	deleteStack(stack);
}