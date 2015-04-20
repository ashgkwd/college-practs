#include <string>
#include <vector>
#include <locale>

enum TokenType {
	ID,
	OP,
	VAL
};

class Token {
public:
	const std::string value;
	const TokenType type;

	Token(std::string v, TokenType t) :
	value(v), type(t) {}
};

std::vector<Token> getTokens (const std::string& expression) {
	const std::locale loc;
	// std::string expression;
	// std::getline(std::cin, expression);
	const int length = expression.size();

	std::vector<Token> tokens;
	
	for (int i = 0; i<length; i++) {
		char c = expression[i];
		std::string token;

		while (std::isalpha(c, loc) or std::isdigit(c)) {
			token += c;
			i++;
			if (i<length) c = expression[i];
			else break;
		}

		if (not token.empty()) {
			// add this `id` or `value` to tokens
			if (std::isdigit(token[0]))
				tokens.push_back(Token(token, TokenType::VAL));
			else
				tokens.push_back(Token(token, TokenType::ID));

			token.clear();
			i--;
		} else {
			// add this `symbol` to tokens
			token += c;
			if (not std::isspace(c, loc)) tokens.push_back(Token(token, TokenType::OP));
			token.clear();
		}
	}

	return tokens;
}
