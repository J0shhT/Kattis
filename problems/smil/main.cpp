#include <iostream>
#include <string>

int main()
{
	std::string input;
	input.reserve(2048);
	std::getline(std::cin, input);
	for (int i = 0; i < input.length(); ++i)
	{
		char c = input[i];
		if (c != ':' && c != ';')
			continue; // nope
		if (i+1 >= input.length())
			break; // hit end

		// possibly a smile
		c = input[++i];
		if (c != ')' && c != '-')
		{
			// nope
			--i;
			continue; 
		}
		if (c == '-' && i+1 >= input.length())
			break; // hit end
		
		if (c == ')')
		{
			// yes (2 letter smile)
			std::cout << i-1 << std::endl;
			continue;
		}
		
		c = input[++i];
		if (c != ')')
		{
			// nope
			--i;
			continue; 
		}

		// yes (3 letter smile)
		std::cout << i-2 << std::endl;
	}
	return 0;
}