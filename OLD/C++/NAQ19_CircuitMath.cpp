#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>

std::vector<char> getTokens(const std::string& str)
{
	std::vector<char> tokens;
	size_t start = 0;
	size_t end = str.find(" ");
	if (end != std::string::npos)
	{
		while (end != std::string::npos)
		{
			char match = str.substr(start, end - start)[0];
			tokens.push_back(match);
			start = end + 1;
			end = str.find(" ", start);
			if (end == std::string::npos && start != str.length())
			{
				char match = str.substr(start, str.length() - 1)[0];
				tokens.push_back(match);
			}
		}
	}
	else
	{
		tokens.push_back(str[0]);
	}
	return tokens;
}

int main()
{
	int n;
	std::cin >> n;

	std::map<char, bool> variables;
	for (int i = 0; i < n; i++)
	{
		char c;
		std::cin >> c;
		bool val = (c == 'T' ? true : false);
		variables.emplace('A' + i, val);
	}

	std::string expression;
	std::cin.ignore();
	std::getline(std::cin, expression);
	std::vector<char> tokens = getTokens(expression);

	std::stack<bool> operands;
	for (char token : tokens)
	{
		if (token == '+' || token == '-' || token == '*')
		{
			bool result;
			if (token == '+')
			{
				bool a, b;
				b = operands.top();
				operands.pop();
				a = operands.top();
				operands.pop();
				result = a || b;
			}
			if (token == '-')
			{
				bool a;
				a = operands.top();
				operands.pop();
				result = !a;
			}
			if (token == '*')
			{
				bool a, b;
				b = operands.top();
				operands.pop();
				a = operands.top();
				operands.pop();
				result = a && b;
			}
			operands.push(result);
		}
		else
		{
			bool value = variables.at(token);
			operands.push(value);
		}
	}
	std::cout << (operands.top() == true ? 'T' : 'F') << "\n";
	return 0;
}