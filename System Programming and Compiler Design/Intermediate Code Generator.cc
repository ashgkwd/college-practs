#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "token.h"
#include "precedence.h"

class Quadruple
{
public:
	const std::string op;
	const std::string arg_1;
	const std::string arg_2;
	const std::string result;

	Quadruple(const std::string& o, const std::string& a1, const std::string& a2, const std::string& r) :
	op(o), arg_1(a1), arg_2(a2), result(r) {}
};

Quadruple getQuadruples (std::vector<Token>& tokens, const int& r, const std::string& lhsvar) {
	std::string op, arg_1, arg_2, result = std::string("r") + std::to_string(r);
	int index = tokens.size() - 2;

	// find first OP from right
	while (not tokens.empty() and tokens[index].type != TokenType::OP) {
		index--;
	}

	// from index, two Token to right are arg_2 and arg_1
	op = tokens[index].value;
	arg_2 = tokens[index + 1].value;
	arg_1 = tokens[index + 2].value;

	// update tokens to reflect operation result
	tokens.erase(tokens.begin() + index, tokens.begin() + index + 3);

	if (tokens.size() <= 1 and lhsvar.size()) {
		// As this is last Quadruple, store its result in lhsvar
		tokens.insert(tokens.begin() + index, Token(lhsvar, TokenType::ID));
		return Quadruple(op, arg_1, arg_2, lhsvar);
	}
	else {
		tokens.insert(tokens.begin() + index, Token(result, TokenType::ID));
		return Quadruple(op, arg_1, arg_2, result);
	}
}

int main () {
	std::string expression;
	std::getline(std::cin, expression);
	std::vector<Token> sourceTokens = getTokens(expression);
	std::string lhsvar;
	
	// separate lhs if present
	if (sourceTokens.size()>2 and sourceTokens[1].value == "=") {
		lhsvar = sourceTokens[0].value;
		sourceTokens.erase(sourceTokens.begin(), sourceTokens.begin() + 2);
	}

	std::vector<Token> tokens = tokensAsPerPrecedence(sourceTokens);
	std::reverse(tokens.begin(), tokens.end());
	 
	std::vector<Quadruple> intermediate_codes;
	int registerCount = 0;

	while (tokens.size() >= 3) {
		intermediate_codes.push_back(getQuadruples(tokens, ++registerCount, lhsvar));
	}

	std::cout << "{Intermediate Codes}" << std::endl;
	for (const Quadruple& q : intermediate_codes) {
		std::cout << q.result << " := " << q.arg_1 << q.op << q.arg_2 << std::endl;
	}
}
