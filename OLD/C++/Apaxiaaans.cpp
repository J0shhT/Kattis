#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string text;
	std::cin >> text;
	text.resize(std::distance(text.begin(),std::unique(text.begin(), text.end())));
	std::cout << text;
}