#include <iomanip>
#include <iostream>

int main()
{
	int m, n;
	std::cin >> m >> n;
	std::cin.ignore();
	int e = 0;
	for (auto i = 0; i < n; ++i)
	{
		char ch;
		for (auto j = 0; j < m; ++j)
		{
			std::cin >> ch;
			if (ch == '.')
				++e;
		}
		std::cin.ignore();
	}
	std::cout << std::setprecision(15);
	std::cout << ((double)e / (double)(m * n)) << std::endl;
}