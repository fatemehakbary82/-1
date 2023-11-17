#include <iostream>
#include<stack>
using namespace std;

struct Queue {
	stack<int> stack1, stack2;

	void enqueue(int x)
	{
		// Move all elements from s1 to s2
		while (!stack1.empty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}

		// Push item into s1
		stack1.push(x);

		// Push everything back to s1
		while (!stack2.empty()) {
			stack1.push(stack2.top());
			stack2.pop();
		}
	}