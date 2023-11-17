#include <iostream>
#include<stack>
using namespace std;
 
struct Queue { 
	stack<int> stack_; 

	// Enqueue an item to the queue 
	void enqueue(int x) 
	{ 
		stack_.push(x); 
	} 

	// Dequeue an item from the queue 
	int dequeue() 
	{ 
		if (stack_.empty()) { 
			cout << "Queue is empty" << endl;; 
			exit(0); 
		} 

		// pop an item from the stack 
		int x = stack_.top(); 
		stack_.pop(); 

		// if stack becomes empty, return 
		// the popped item 
		if (stack_.empty()) 
			return x; 

		// recursive call 
		int ret = dequeue(); 

		// push popped item back to the stack 
		stack_.push(x); 

		// return the result of deQueue() call 
		return ret; 
	} 
}; 

