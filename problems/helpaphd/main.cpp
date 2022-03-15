#include <iostream>
#include <string>
#include <climits>

int main()
{
	int n;
	std::cin >> n;
	while (n-- > 0)
	{
		int a, b;
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cout << "skipped" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			continue;
		}
		std::getchar();
		std::cin >> b;
		std::cout << a+b << std::endl;
	}
}