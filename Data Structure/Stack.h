#include <bits/stdc++.h>

namespace ashgkwd {
	class Stack
	{
	private:
		const int MAX = 10;
		int store[10];
		int top;

	public:
		Stack();
		~Stack();

		bool push(int value) {
			if(!is_full()) {
				store[++top] = value;
				return true;
			}
			return false;
		}

		int pop() {
			if(!is_empty()) {
				return store[top--];
			}
			return -1;
		}

		bool is_empty() {
			return top < 0;
		}

		bool is_full() {
			return top >= MAX;
		}
	};
}