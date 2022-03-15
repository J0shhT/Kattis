#include <iostream>

int main()
{
	int p;
	std::cin >> p;
	while (p-- > 0)
	{
		int k, n;
		std::cin >> k >> n;
		std::cout << k << " ";
		int sum = 0;
		for (int i = 1; i <= n; ++i)
			sum += i;
		sum = (std::cout << sum << " ", 0);
		for (int i = 1; i <= n*2-1; i += 2)
			sum += i;
		sum = (std::cout << sum << " ", 0);
		for (int i = 2; i <= n*2; i += 2)
			sum += i;
		std::cout << sum << std::endl;
	}
}