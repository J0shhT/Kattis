#include <iostream>
#include <cmath>

int main()
{
	static const double CONV = (1000.0*(5280.0/4854.0));
	double miles;
	std::cin >> miles;
	int result = static_cast<int>(std::round(miles * CONV));
	std::cout << result << std::endl;
	return 0;
}