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
	for (const std::string& t : tokensAsPerPrecedence(tokens)) {
		std::cout << t << std::endl;
	}
}
