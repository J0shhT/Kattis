#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

std::map<std::string, int> definitions;

void def(std::string name, int val)
{
	definitions[name] = val;
}

std::string calc(std::vector<std::string> defs, std::vector<char> operations)
{
	int result = 0;
	if (definitions.find(defs[0]) == definitions.end())
	{
		return "unknown";
	}
	result = definitions[defs[0]];
	for (size_t i = 0; i < operations.size(); i++)
	{
		char operation = operations[i];
		std::string rhs = "";
		if (operation != '=')
		{
			if (i + 1 >= defs.size())
			{
				rhs = "";
			}
			else
			{
				rhs = defs[i + 1];
			}
		}
		if (rhs != "" && (definitions.find(rhs) == definitions.end()))
		{
			return "unknown";
		}
		else
		{
			if (operation == '+')
			{
				if (rhs != "")
				{
					result += definitions[rhs];
				}
			}
			else if (operation == '-')
			{
				if (rhs != "")
				{
					result -= definitions[rhs];
				}
			}
			else if (operation == '=')
			{
				for (auto& element : definitions)
				{
					if (element.second == result)
					{
						return element.first;
					}
				}
				return "unknown";
			}
		}
	}
	return "unknown";
}

void clear()
{
	definitions.clear();
}

void processCommand(std::string cmd)
{
	if (cmd == "clear")
	{
		clear();
	}
	else
	{
		std::istringstream cmdStream(cmd);
		std::string temptoken;
		std::vector<std::string> tokens;
		while (std::getline(cmdStream, temptoken, ' '))
		{
			tokens.push_back(temptoken);
		}
		if (tokens[0] == "def")
		{
			def(tokens[1], std::stoi(tokens[2]));
		}
		else if (tokens[0] == "calc")
		{
			tokens.erase(tokens.begin());
			std::vector<std::string> defs;
			std::vector<char> operations;
			for (std::string& token : tokens)
			{
				if (token.size() == 1)
				{
					if (token[0] == '+' || token[0] == '-' || token[0] == '=')
					{
						operations.push_back(token[0]);
					}
				}
				else
				{
					defs.push_back(token);
				}
			}
			std::string operationText = "";
			for (std::string& element : tokens)
			{
				operationText += element + " ";
			}
			std::cout << operationText << calc(defs, operations) << "\n";
		}
	}
}

int main()
{
	std::string cmd;
	std::getline(std::cin, cmd);
	while (!std::cin.eof())
	{
		processCommand(cmd);
		std::getline(std::cin, cmd);
	}
}