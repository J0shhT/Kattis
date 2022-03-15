#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

int main()
{
	double h, v;
	std::cin >> h;
	std::cin >> v;
	std::cout << ceil(h / sin(v * (M_PI / 180.0))) << "\n";
	return 0;
}