#include <iostream>
#include<stack>

using namespace std;

struct Queue {
	stack<int> stack;

	// Enqueue an item to the queue
    	void enqueue(int x)
	{
		stack.push(x);
	}

    // Dequeue an item from the queue
	int dequeue()
	{
		if (stack.empty()) {
			cout << "Queue is empty" << endl;;
			exit(0);
		}

		// pop an item from the stack
		int x = stack.top();
		stack.pop();

		// if stack becomes empty, return
		// the popped item
		if (stack.empty())
			return x;

		// recursive call
		int ret = dequeue();

		// push popped item back to the stack
		stack.push(x);

		// return the result of deQueue() call
		return ret;
	}
};
