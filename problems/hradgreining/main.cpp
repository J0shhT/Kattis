#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;
	if (s.find("COV") != std::string::npos)
		std::cout << "Veikur!" << std::endl;
	else
		std::cout << "Ekki veikur!" << std::endl;
}