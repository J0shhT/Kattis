#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, x;
	std::cin >> n >> x;

	if (n > x)
	{
		std::cout << "Neibb\n";
		return 0;
	}

	int sum = 0;
	int v;
	for (auto i = n; i > 0; --i)
	{
		std::cin >> v;
		sum += v;
		if (sum + (i - 1) > x)
		{
			std::cout << "Neibb\n";
			return 0;
		}
	}

	std::cout << "Jebb\n";
}