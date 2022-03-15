#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		double q, y;
		std::cin >> q;
		std::cin >> y;
		sum += q * y;
	}
	std::cout << sum << "\n";
	return 0;
}