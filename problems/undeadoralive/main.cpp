#include <iostream>
#include <string>

int main()
{
	std::string input;
	std::getline(std::cin, input);
	bool hasSmiley = input.find(":)") != std::string::npos;
	bool hasFrown = input.find(":(") != std::string::npos;
	if (hasSmiley && !hasFrown)
		std::cout << "alive";
	else if (!hasSmiley && hasFrown)
		std::cout << "undead";
	else if (hasSmiley && hasFrown)
		std::cout << "double agent";
	else
		std::cout << "machine";
	std::cout << std::endl;
}