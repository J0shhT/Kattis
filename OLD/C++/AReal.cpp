#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
	uint64_t area;
	double length;
	std::cin >> area;

	length = sqrt(area) * 4;

	std::cout << std::setprecision(16) << length << "\n";
}