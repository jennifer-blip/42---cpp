#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>

RPN::RPN() {}
RPN::RPN(const RPN&) {}
RPN& RPN::operator=(const RPN&){
	return *this;
}
RPN::~RPN() {}

static bool	isOperator(const std::string& token){
	return token.size() && 
		(token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

static bool	isNumber(const std::string& token){
	if (token.empty()) return false;
	size_t	i = 0;
	if (token[i] == '+' || token[i] == '-')
		i++;
	if (i == token.size()) return false;
	for (; i < token.size(); i++){
		if (!isdigit(token[i]))
			return false;
	}
	return true;
}

int	RPN::calculate(const std::string& expression){
	std::stack<int> s;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token){
		if (isNumber(token)){
			std::istringstream num(token);
			int n;
			num >> n;
			s.push(n);
		} else if (isOperator(token)){
			if (s.size() < 2)
				throw std::runtime_error("Invalid expression");
			int	b = s.top(); s.pop();
			int	a = s.top(); s.pop();
			if (token == "+") s.push(a + b);
			else if (token == "-") s.push(a - b);
			else if (token == "*") s.push(a * b);
			else {
				if (b == 0) throw std::runtime_error("Division by zero");
				s.push(a / b);
			}
		}
		else {
				throw std::runtime_error("Invalid token: " + token);
			}
	}
	if (s.size() != 1 || expression.find_first_of("+-*/") == std::string::npos)
		throw std::runtime_error("Invalid expression");
	return s.top();
}