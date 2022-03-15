#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
	double a, b, c, d;
	std::cin >> a >> b >> c >> d;
	double s = (a+b+c+d)/2;
	std::cout << std::setprecision(16) << sqrt((s-a)*(s-b)*(s-c)*(s-d)) << std::endl;
	return 0;
}