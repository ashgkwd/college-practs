#include <iostream>
#include <string>
#include <vector>
#include "token.h"

int getPrecedence (const std::string& first, const std::string& second) {
	// col: op in stack
	// row: op in next input
	//
	//   + - ) ( * ^
	// + > > > < < <
	// - > > > < < <
	// ) > > > > > >
	// ( < < > < < <
	// * > > > < > >
	// ^ > > > < < >

	const int precedence[][6] = {
		{1, 1, 1, 0, 0, 0},
		{1, 1, 1, 0, 0, 0},
		{1, 1, 1, 1, 1, 1},
		{0, 0, 1, 0, 0, 0},
		{1, 1, 1, 0, 1, 1},
		{1, 1, 1, 0, 0, 1}
	};

	const int index[][6] = {
		{'+', '-', ')', '(', '*', '^'},
		{0, 1, 2, 3, 4, 5}
	};

	int indexOfFirst = 0, indexOfSecond = 0;
	for (int i = 0; i<6; i++) {
		if (index[0][i] == first.c_str()[0])
			indexOfFirst = index[1][i];
		if (index[0][i] == second.c_str()[0])
			indexOfSecond = index[1][i];
	}

	return precedence[indexOfFirst][indexOfSecond];
}

int main () {
	std::string expression;
	std::getline(std::cin, expression);
	std::vector<Token> tokens = getTokens(expression);
	const int length = tokens.size();

	std::vector<std::string> op_stack;
	std::vector<std::string> output;

	for (int i = 0; i<length; i++) {
		const Token& t = tokens[i];
		if (t.type == TokenType::OP) {
			if (t.value != ")") {
				while (not op_stack.empty() and getPrecedence(op_stack.back(), t.value)) {
					output.push_back(op_stack.back());
					op_stack.pop_back();
				}
				op_stack.push_back(t.value);
			} else {
				while (not op_stack.empty() and op_stack.back() != "(") {
					output.push_back(op_stack.back());
					op_stack.pop_back();
				}
				if (op_stack.back() == "(")
					op_stack.pop_back();
			}
		} else {
			output.push_back(t.value);
		}
	}

	while (not op_stack.empty()) {
		output.push_back(op_stack.back());
		op_stack.pop_back();
	}

	std::cout << "{Output After Rearranging As Per Operator Precedence}" << std::endl;
	for (const std::string& t : output) {
		std::cout << t << std::endl;
	}
}
