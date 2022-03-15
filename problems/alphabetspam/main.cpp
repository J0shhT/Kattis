#include <iostream>
#include <string>
#include <cctype>

int main()
{
	std::string input;
	std::getline(std::cin, input);
	size_t numCharacters = input.length();
	size_t numWhitespace = 0, numLower = 0, numUpper = 0, numSymbols = 0;
	for (char c : input)
	{
		if (c == '_')
			++numWhitespace;
		else if (std::islower(c))
			++numLower;
		else if (std::isupper(c))
			++numUpper;
		else
			++numSymbols;
	}
	std::cout.precision(15);
	std::cout << (double)numWhitespace / numCharacters << '\n';
	std::cout << (double)numLower / numCharacters << '\n';
	std::cout << (double)numUpper / numCharacters << '\n';
	std::cout << (double)numSymbols / numCharacters << std::endl;
	return 0;
}