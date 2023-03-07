#include <cmath>
#include <iostream>

int main()
{
	double x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;
	std::cout << (std::abs(x2 - x1) * std::abs(y2 - y1)) << std::endl;
}