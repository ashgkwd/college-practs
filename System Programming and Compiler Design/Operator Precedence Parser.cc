#include <iostream>
#include <string>
#include <vector>
#include "token.h"
#include "precedence.h"

int main () {
	std::string expression;
	std::getline(std::cin, expression);
	std::vector<Token> tokens = getTokens(expression);

	std::cout << "{Output After Rearranging As Per Operator Precedence}" << std::endl;
	std::cout << "{TYPE\tVALUE}" << std::endl;
	for (const Token& t : tokensAsPerPrecedence(tokens)) {
		std::cout << t.type << "\t" << t.value << std::endl;
	}
}
