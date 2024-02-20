#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;
	int n;
	std::cin >> n;
	std::string result;
	result.reserve(s.length() * n);
	while (n-- > 0)
		result.append(s);
	std::cout << result << std::endl;
}