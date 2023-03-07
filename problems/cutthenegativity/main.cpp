#include <iostream>
#include <sstream>

int main()
{
	int n;
	std::cin >> n;

	int m = 0;
	std::stringstream output;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int cost;
			std::cin >> cost;
			if (cost != -1)
			{
				++m;
				output << i << ' ' << j << ' ' << cost << std::endl;
			}
		}
	}
	std::cout << m << std::endl << output.rdbuf();
}