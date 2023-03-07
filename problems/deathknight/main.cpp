#include <iostream>
#include <string>

int main()
{
	int n;
	std::cin >> n;

	int wins = 0;
	while (n--)
	{
		std::string s;
		std::cin >> s;
		if (s.find("CD") == std::string::npos)
			++wins;
	}

	std::cout << wins << std::endl;
}