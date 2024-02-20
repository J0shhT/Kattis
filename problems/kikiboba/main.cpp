#include <algorithm>
#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;
	auto bCount = std::count(s.begin(), s.end(), 'b');
	auto kCount = std::count(s.begin(), s.end(), 'k');
	if (bCount > kCount)
		std::cout << "boba";
	else if (bCount < kCount)
		std::cout << "kiki";
	else if (bCount == 0)
		std::cout << "none";
	else
		std::cout << "boki";
	std::cout << std::endl;
}