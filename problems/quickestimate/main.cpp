#include <iostream>
#include <string>

int main()
{
	int N;
	std::cin >> N;
	std::cin.ignore(1, '\n');

	while (N-- > 0)
	{
		std::string s;
		std::getline(std::cin, s);
		std::cout << s.length() << '\n';
	}
}