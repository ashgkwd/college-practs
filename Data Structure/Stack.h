namespace ashgkwd {

#ifndef H_STACK_ASHGKWD
#define H_STACK_ASHGKWD 8

	class Stack
	{
	private:
		static const int MAX = 10;
		int store[10];
		int top;

	public:
		Stack();

		bool push(int value);
		int pop();

		bool is_empty();
		bool is_full();
	};

#endif
}
