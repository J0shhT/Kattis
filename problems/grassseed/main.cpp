#include <iostream>
#include <iomanip>

int main()
{
	double C;
	int L;
	std::cin >> C >> L;
	double area = 0;
	while (L-->0)
	{
		double w, l;
		std::cin >> w >> l;
		area += w * l;
	}
	std::cout << std::setprecision(10) << area * C << std::endl;
	return 0;
}