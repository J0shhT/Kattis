#include <iomanip>
#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	std::cout << std::setprecision(15);
	std::cout << ((double)n * 0.09144) << std::endl;
}