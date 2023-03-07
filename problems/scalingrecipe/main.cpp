#include <cmath>
#include <iostream>

int main()
{
	int n, x, y;
	std::cin >> n >> x >> y;
	double f = (double)y / x;
	while (n--)
	{
		int a;
		std::cin >> a;
		std::cout << (int)std::round(f * a) << '\n';
	}
}