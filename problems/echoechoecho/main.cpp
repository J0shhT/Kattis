#include <iostream>
#include <string>

int main()
{
	std::string input;
	std::getline(std::cin, input);
	for (int i = 1; i <= 3; ++i)
	{
		std::cout << input;
		if (i != 3)
			std::cout << " ";
	}
	std::cout << std::endl;
}