// Section 4.2b Exercise 5
// Test.cpp
// [Author] Cliff Chen
// [Description] Test PointArray.
// [Modifications]
// 2021-10-06  CC established the 1st version.

#include "Stack.cpp"
#include <iostream>
using namespace std;

void main()
{
	Stack<int> stack1;

	// Test Push().
	for (int i = 0; i < 4; i++)
	{
		try
		{
			stack1.Push(i);
		}
		catch (StackException& ex)
		{
			cout << ex.GetMessage() << endl;
		}
	}

	Stack<int> stack2(stack1); // Test copy constructor

	Stack<int> stack3 = stack2; // Test assignment operator

	// Test Pop().
	for (int i = 0; i < 4; i++)
	{
		try 
		{
			cout << stack3.Pop() << endl;
		}
		catch (StackException& ex)
		{
			cout << ex.GetMessage() << endl;
		}

	}
}