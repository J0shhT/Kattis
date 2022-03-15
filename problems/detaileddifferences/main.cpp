#include <iostream>
#include <string>

int main()
{
	int n;
	std::cin >> n;
	std::cin.ignore();
	for (int i = 0; i < n; i++)
	{
		std::string s1, s2;
		std::getline(std::cin, s1);
		std::getline(std::cin, s2);
		std::cout << s1 << '\n';
		std::cout << s2 << '\n';
		for (size_t k = 0; k < s1.length(); k++)
		{
			if (s1[k] == s2[k])
				std::cout << '.';
			else
				std::cout << '*';
		}
		std::cout << "\n\n";
	}
	return 0;
}
