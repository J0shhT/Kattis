#include <cctype>
#include <iostream>
#include <string>

#define BIT_SET(n, i) (((n) >> (3 - (i))) & 1 == 1)
#define TO_INT(c)     (uint8_t(c - '0'))

int main()
{
	std::string input;
	std::getline(std::cin, input);
	for (size_t i = 0; i < 4; ++i)
	{
		std::cout << (BIT_SET(TO_INT(input[0]), i) ? '*' : '.') << ' ';
		std::cout << (BIT_SET(TO_INT(input[1]), i) ? '*' : '.') << "   ";
		std::cout << (BIT_SET(TO_INT(input[2]), i) ? '*' : '.') << ' ';
		std::cout << (BIT_SET(TO_INT(input[3]), i) ? '*' : '.') << '\n';
	}
}