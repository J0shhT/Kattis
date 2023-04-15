#include <algorithm>
#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::getline(std::cin, s);
	std::cout << (s.substr(std::max<size_t>(0, s.length() - 3)) == "eh?" ? "Canadian!" : "Imposter!") << std::endl;
}