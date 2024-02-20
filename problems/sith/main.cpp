#include <cmath>
#include <iostream>
#include <limits>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int a, b, diff;
	std::cin >> a >> b >> diff;
	if (a >= b)
		std::cout << "VEIT EKKI";
	else if (a - b == diff)
		std::cout << "JEDI";
	else
		std::cout << "SITH";
	std::cout << std::endl;
}