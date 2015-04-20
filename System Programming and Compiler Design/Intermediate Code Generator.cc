#include <iostream>
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

std::vector<Token> getTokens () {
	const std::locale loc;
	std::string expression;
	std::getline(std::cin, expression);
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

class Quadruples
{
public:
	const std::string op;
	const std::string arg_1;
	const std::string arg_2;
	const std::string result;

	Quadruples(const std::string& o, const std::string& a1, const std::string& a2, const std::string& r) :
	op(o), arg_1(a1), arg_2(a2), result(r) {}
};

Quadruples getQuadruples (std::vector<Token>& tokens, const int& result, const std::string& arg_2) {
	std::string op;
	std::string arg_1;

	if (tokens.size() >= 2) {
		op = tokens.back().value;
		tokens.pop_back();

		arg_1 = tokens.back().value;
		tokens.pop_back();
	}

	if (op == "=") {
		// arg_1 is register ` 'r'+arg2 `, result is `arg_1`
		return Quadruples("", std::string("r") + arg_2, "", arg_1);
	}

	return Quadruples(op, arg_1, arg_2, std::string("r") + std::to_string(result));
}

int main () {
	std::vector<Token> tokens = getTokens();
	 
	std::vector<Quadruples> intermediate_codes;
	int registerCount = 1;

	std::string arg_2 = tokens.back().value;
	tokens.pop_back();

	intermediate_codes.push_back(getQuadruples(tokens, registerCount, arg_2));
	
	while (not tokens.empty()) {
		arg_2 = std::to_string(registerCount);
		registerCount++;
		intermediate_codes.push_back(getQuadruples(tokens, registerCount, arg_2));
	}

	std::cout << "{Intermediate Codes}" << std::endl;
	for (const Quadruples& q : intermediate_codes) {
		std::cout << q.result << " := " << q.arg_1 << q.op << q.arg_2 << std::endl;
	}
}