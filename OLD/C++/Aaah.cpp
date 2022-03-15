#include <iostream>
#include <string>

int main()
{
	std::string input1, input2;
	std::cin >> input1;
	std::cin >> input2;
	if (input2.size() > input1.size()) std::cout << "no"; else std::cout << "go";
}