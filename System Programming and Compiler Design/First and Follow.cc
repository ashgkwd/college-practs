#include <iostream>
#include <locale>
#include <vector>
#include <set>
#include <utility>
#include "token.h"

typedef std::pair<char, std::set<std::string> > charstrset;

// TODO: Implement caching using memoization

/*
Input:
3
S aAB 0 k
A k
B Ab

Output:
NT First   Follow
S  a 0 k   $
A  k       b k
B  k       $
*/

std::set<char> getFirstOf (char NT, std::vector<charstrset> productions) {
	std::set<char> setOfFirsts;

	for (auto rules : productions) {
		if (rules.first == NT) {
			for (auto p : rules.second) {
				std::cout << "{debug} NT " << NT << " rule " << p << std::endl;
				if ((p[0] >= 'a' and p[0] <= 'z') or p[0] == '0') {
					setOfFirsts.insert(p[0]);
				} else {
					for (auto f : getFirstOf(p[0], productions)) {
						setOfFirsts.insert(f);
					}
				}
			}
		}
	}

	return setOfFirsts;
}

charstrset readProduction () {
	charstrset productions;
	std::set<std::string> rules;
	std::string expression;
	std::getline(std::cin, expression);
	std::cout << "{debug} done reading " << expression << std::endl;

	std::vector<Token> tokens = getTokens(expression);
	for (int i = 1; i < tokens.size(); i++) {
		 rules.insert(tokens[i].value);
	}

	return charstrset(tokens[0].value.c_str()[0], rules);
}

int main () {
	std::vector<charstrset> productions;
	std::string NT, T;
	int totalProductions;

	std::cin >> totalProductions;
	std::cin.ignore();
	while (totalProductions--) {
		productions.push_back(readProduction());
	}

	for (auto p : productions) {
		std::cout << "{debug} current p " << p.first << std::endl;
		for (auto first : getFirstOf(p.first, productions)) {
			std::cout << first << std::endl;
		}
	}

	return 0;
}