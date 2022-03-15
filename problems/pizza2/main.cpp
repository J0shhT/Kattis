#include <iostream>
#include <cmath>

int main()
{
	double R, C;
	std::cin >> R >> C;
	std::cout.precision(16);
	std::cout << (((R-C)*(R-C))/(R*R))*100.0 << std::endl;
}