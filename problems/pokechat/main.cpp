#include <cmath>
#include <iostream>
#include <string>

int main()
{
	std::string alphabet, codes;
	std::getline(std::cin, alphabet);
	std::getline(std::cin, codes);

	int length = codes.length() / 3;
	for (int i = 0; i < length; ++i)
	{
		int id = 0;
		for (int j = 0; j < 3; ++j)
		{
			char ch = codes[i * 3 + j];
			int digit = unsigned(ch - '0');
			id += digit * std::pow(10, 2 - j);
		}
		std::cout << alphabet[id - 1];
	}
	std::cout << std::endl;
}