#include <bits/stdc++.h>
#include "Stack.h"
using namespace ashgkwd;

Stack::Stack () : top(-1) {}

bool Stack::push(int value) {
	if(!is_full()) {
		store[++top] = value;
		return true;
	}
	return false;
}

int Stack::pop() {
	if(!is_empty()) {
		return store[top--];
	}
	return -1;
}

bool Stack::is_empty() {
	return top < 0;
}

bool Stack::is_full() {
	return top >= MAX;
}
