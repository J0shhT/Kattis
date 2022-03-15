#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

int main()
{
	std::unordered_map<std::string, int> vars;
	std::string line;
	while (!std::cin.eof())
	{
		std::getline(std::cin, line);
		std::istringstream input(line);
		std::string command;
		input >> command;
		if (command == "define")
		{
			int val;
			std::string name;
			input >> val;
			input >> name;
			vars[name] = val;
		}
		else if (command == "eval")
		{
			std::string var1, op, var2;
			input >> var1 >> op >> var2;
			if (vars.count(var1) == 0 || vars.count(var2) == 0)
			{
				std::cout << "undefined\n";
				continue;
			}
			else
			{
				bool result;
				switch (op[0])
				{
					case '<':
						result = vars[var1] < vars[var2];
						break;
					case '=':
						result = vars[var1] == vars[var2];
						break;
					case '>':
						result = vars[var1] > vars[var2];
						break;
					default:
						break;
				}
				std::cout << (result ? "true" : "false") << '\n';
			}
		}
	}
	return 0;
}