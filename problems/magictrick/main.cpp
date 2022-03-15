#include <iostream>
#include <string>

static bool letters[('z'-'a')+1] = { false };

int main()
{
	std::string input;
	std::getline(std::cin, input);
	for (char c : input)
	{
		size_t i = c-'a';
		if (letters[i] == true)
		{
			std::cout << 0 << std::endl;
			return 0;
		}
		letters[i] = true;
	}
	std::cout << 1 << std::endl;
	return 0;
}