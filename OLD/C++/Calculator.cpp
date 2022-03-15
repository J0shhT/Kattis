#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <iomanip>

int comparePrecedence(char a, char b)
{
	if ((a == '*' || a == '/') && (b == '+' || b == '-'))
		return 1;
	if ((a == '+' || a == '-') && (b == '*' || b == '/'))
		return -1;
	return 0;
}

std::string convertToPostfix(const std::string &expression)
{
	std::string postfix;
	std::stack<char> operators;
	std::string numberBuilder;
	char lastToken = 0;
	for (char c : expression)
	{
		if (c >= '0' && c <= '9')
		{
			//operand
			numberBuilder += c;
		}
		else if (c == '-' && (lastToken == 0 || lastToken == '(' || lastToken == '*' || lastToken == '/' || lastToken == '+' || lastToken == '-'))
		{
			//negation
			numberBuilder += '-';
		}
		else
		{
			if (numberBuilder.size() > 0)
			{
				if (postfix.size() > 0)
				{
					postfix += " ";
				}
				postfix += numberBuilder;
				numberBuilder = "";
			}
			if (c == '*' || c == '/' || c == '+' || c == '-')
			{
				//operator token
				while (operators.size() > 0 && (comparePrecedence(operators.top(), c) >= 0 && operators.top() != '('))
				{
					char op = operators.top();
					operators.pop();
					postfix += std::string(" ") + op;
				}
				operators.push(c);
			}
			else if (c == '(')
			{
				//starting bracket
				operators.push(c);
			}
			else if (c == ')')
			{
				//ending bracket
				while (operators.top() != '(')
				{
					char op = operators.top();
					operators.pop();
					postfix += std::string(" ") + op;
				}
				if (operators.top() == '(')
				{
					operators.pop();
				}
			}
		}
		if (c != ' ')
			lastToken = c;
	}
	if (numberBuilder.size() > 0)
	{
		if (postfix.size() > 0)
		{
			postfix += " ";
		}
		postfix += numberBuilder;
	}
	while (operators.size() > 0)
	{
		char op = operators.top();
		operators.pop();
		postfix += std::string(" ") + op;
	}
	return postfix;
}

std::vector<std::string> getTokens(const std::string& str)
{
	std::vector<std::string> tokens;
	size_t start = 0;
	size_t end = str.find(" ");
	while (end != std::string::npos)
	{
		std::string match = str.substr(start, end - start);
		tokens.push_back(match);
		start = end + 1;
		end = str.find(" ", start);
		if (end == std::string::npos && start != str.length())
		{
			std::string match = str.substr(start, str.length() - 1);
			tokens.push_back(match);
		}
	}
	return tokens;
}

int main()
{
	std::string expressionString;
	while (std::getline(std::cin, expressionString))
	{
		std::string expression = convertToPostfix(expressionString);
		std::vector<std::string> tokens = getTokens(expression);
		std::stack<double> operands;
		for (std::string token : tokens)
		{
			if (token == "+" || token == "-" || token == "*" || token == "/")
			{
				double a, b, result;
				b = operands.top();
				operands.pop();
				a = operands.top();
				operands.pop();
				if (token == "+")
					result = a + b;
				if (token == "-")
					result = a - b;
				if (token == "*")
					result = a * b;
				if (token == "/")
					result = a / b;
				operands.push(result);
			}
			else
			{
				int value = std::stoi(token);
				operands.push(value);
			}
		}
		std::cout << std::fixed << std::setprecision(2) << operands.top() << "\n";
	}
	return 0;
}