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
    

};