#include <cmath>
#include <iomanip>
#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	while (n-- > 0)
	{
		double x, y;
		std::cin >> x >> y;

		double h = (x + y - sqrt(x * x - x * y + y * y)) / 6.0;
		double v = 4.0 * pow(h, 3.0) - 2.0 * x * h * h - 2.0 * y * h * h + x * y * h;
		std::cout << std::setprecision(12) << v << std::endl;
	}
}