#include <iostream>

int main()
{
	int a;
	std::cin >> a;
	double r1 = 100.0 / a;
	double r2 = 100.0 / (100 - a);
	std::printf("%.10f\n%.10f\n", r1, r2);
}