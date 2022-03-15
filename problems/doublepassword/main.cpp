#include <cmath>
#include <iostream>

int main()
{
	std::string s1, s2;
	std::getline(std::cin, s1);
	std::getline(std::cin, s2);
	int n = 0;
	for (size_t i = 0; i < s1.length() && i < s2.length(); ++i)
		if (s1[i] != s2[i])
			++n;
	std::cout << pow(2, n) << '\n';
}