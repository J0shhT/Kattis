#include <iostream>
#include <string>

int main()
{
	std::string input;
	std::cin >> input;
	size_t index = input.find_first_of('a');
	std::cout << input.substr(index);
}