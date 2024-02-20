#include <algorithm>
#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;
	std::reverse(s.begin(), s.end());
	std::cout << s << std::endl;
}