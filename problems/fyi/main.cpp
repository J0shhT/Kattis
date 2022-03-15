#include <iostream>
#include <string>

int main()
{
	std::string n;
	std::getline(std::cin, n);
	std::cout << (n[0] == '5' && n[1] == '5' && n[2] == '5' ? 1 : 0) << std::endl;
	return 0;
}