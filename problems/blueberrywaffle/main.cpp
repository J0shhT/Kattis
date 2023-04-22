#include <cmath>
#include <iostream>

int main()
{
	int r, f;
	std::cin >> r >> f;
	std::cout << (int(std::round(double(f) / r)) % 2 == 0 ? "up" : "down") << std::endl;
}