#include <iostream>

int main()
{
	double L, R;
	std::cin >> L >> R;
	std::cout << (2 * ((L / 2) * (L / 2)) <= R * R ? "fits" : "nope") << '\n';
}