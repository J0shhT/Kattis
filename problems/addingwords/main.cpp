#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <sstream>

// template<typename T>
// static void printVars(const T& vars)
// {
// 	for (auto iter = vars.begin(); iter != vars.end(); ++iter)
// 	{
// 		auto key = iter->first;
// 		auto value = iter->second;
// 		std::cout << key << " = " << value << "; ";
// 	}
// 	std::cout << std::endl;
// }

// template<typename T>
// static void printVec(const std::vector<T> vec)
// {
// 	for (T val : vec)
// 	{
// 		std::cout << val << " ";
// 	}
// 	std::cout << std::endl;
// }

int main()
{
	std::unordered_map<std::string, int> vars;
	std::unordered_map<int, std::string> varsInverse;

	std::string line;
	while (std::getline(std::cin, line))
	{
		std::vector<std::string> tokens;
		{
			std::stringstream token;
			for (char c : line)
			{
				if (c == ' ')
				{
					tokens.push_back(token.str());
					token.str("");
					continue;
				}
				else
				{
					token << c;
				}
				
			}
			if (!token.str().empty())
				tokens.push_back(token.str());
		}

		if (tokens.empty()) break;
		std::string command = tokens.front();
		if (command == "clear")
		{
			vars.clear();
			varsInverse.clear();
		}
		else if (command == "def")
		{
			std::string varName = tokens.at(1);
			int varValue = std::stoi(tokens.at(2));
			if (vars.count(varName) != 0)
			{
				int currentValue = vars[varName];
				varsInverse.erase(currentValue);
			}
			vars[varName] = varValue;
			varsInverse[varValue] = varName;
		}
		else if (command == "calc")
		{
			std::vector<std::string> postfix;
			//postfix.reserve(tokens.size()-1);
			std::stack<std::string> tokenStack;
			for (auto iter = (tokens.begin()+1); iter != tokens.end(); ++iter)
			{
				std::string token = *iter;
				if (token == "=")
					continue;
				if (token == "+" || token == "-")
				{
					while (!tokenStack.empty())
					{
						postfix.push_back(tokenStack.top());
						tokenStack.pop();
					}
					tokenStack.push(token);
				}
				else
				{
					postfix.push_back(token);
				}
			}
			while (!tokenStack.empty())
			{
				postfix.push_back(tokenStack.top());
				tokenStack.pop();
			}

			bool isUnknown = false;
			std::stack<int> operandStack;
			for (const std::string token : postfix)
			{
				if (token == "+" || token == "-")
				{
					int op2 = operandStack.top();
					operandStack.pop();
					int op1 = operandStack.top();
					operandStack.pop();
					if (token == "+")
						operandStack.push(op1 + op2);
					else
						operandStack.push(op1 - op2);
				}
				else
				{
					if (vars.count(token) == 0)
					{
						isUnknown = true;
						break;
					}
					else
					{
						operandStack.push(vars[token]);
					}
				}
			}

			std::string equationResult = "";
			if (isUnknown == true)
			{
				equationResult = "unknown";
			}
			else
			{
				int answer = operandStack.top();
				if (varsInverse.count(answer) == 0)
					equationResult = "unknown";
				else
					equationResult = varsInverse[answer];
			}
			
			std::stringstream equation;
			for (auto iter = (tokens.begin()+1); iter != tokens.end(); ++iter)
			{
				equation << *iter;
				equation << " ";
			}

			//printVars(vars);
			//printVars(varsInverse);
			//printVec<std::string>(postfix);
			std::cout << equation.str() << equationResult << std::endl;
		}
	}
	return 0;
}