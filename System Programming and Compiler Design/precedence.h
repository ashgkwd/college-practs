#include <iostream>
#include <string>
#include <vector>
#include "token.h"

#ifndef AG_PRECEDENCE_H_1
#define AG_PRECEDENCE_H_1 221

int getPrecedence (const std::string& first, const std::string& second) {
	// col: op in stack
	// row: op in next input
	//
	//   + - ) ( * ^ =
	// + > > > < < < >
	// - > > > < < < >
	// ) > > > > > > >
	// ( < < > < < < >
	// * > > > < > > >
	// ^ > > > < < > >
	// = < < < < < < <

	const int precedence[][7] = {
		{1, 1, 1, 0, 0, 0, 1},
		{1, 1, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1},
		{0, 0, 1, 0, 0, 0, 1},
		{1, 1, 1, 0, 1, 1, 1},
		{1, 1, 1, 0, 0, 1, 1},
		{0, 0, 0, 0, 0, 0, 0}
	};

	const int index[][7] = {
		{'+', '-', ')', '(', '*', '^', '='},
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


std::vector<Token> tokensAsPerPrecedence (const std::vector<Token>& tokens) {
	const int length = tokens.size();

	std::vector<Token> op_stack;
	std::vector<Token> output;

	for (int i = 0; i<length; i++) {
		const Token& t = tokens[i];
		if (t.type == TokenType::OP) {
			if (t.value != ")") {
				while (not op_stack.empty() and getPrecedence(op_stack.back().value, t.value)) {
					output.push_back(op_stack.back());
					op_stack.pop_back();
				}
				op_stack.push_back(t);
			} else {
				while (not op_stack.empty() and op_stack.back().value != "(") {
					output.push_back(op_stack.back());
					op_stack.pop_back();
				}
				if (op_stack.back().value == "(")
					op_stack.pop_back();
			}
		} else {
			output.push_back(t);
		}
	}

	while (not op_stack.empty()) {
		output.push_back(op_stack.back());
		op_stack.pop_back();
	}

	return output;
}

#endif
