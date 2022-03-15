#include <iostream>
#include <string>

int main()
{
	std::string input;
	std::getline(std::cin, input);
	size_t size1 = input.find_first_of('(');
	size_t size2 = input.size() - size1 - 2;
	std::cout << (size1 == size2 ? "correct" : "fix") << '\n';
}