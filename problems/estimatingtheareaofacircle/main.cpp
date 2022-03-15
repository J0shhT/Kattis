#define _USE_MATH_DEFINES

#include <cmath>
#include <iomanip>
#include <iostream>

int main()
{
	double r;
	int m, c;
	std::cin >> r >> m >> c;
	std::cout.precision(10);
	while (r != 0.0 && m != 0 && c != 0)
	{
		double area = (r * 2) * (r * 2);
		double ratio = double(c) / double(m);
		std::cout << M_PI * r * r << ' ' << area * ratio << '\n';
		std::cin >> r >> m >> c;
	}
}