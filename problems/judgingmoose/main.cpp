#include <algorithm>
#include <iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;
	if (a + b == 0)
		std::cout << "Not a moose";
	else if (a == b)
		std::cout << "Even " << a + b;
	else
		std::cout << "Odd " << std::max(a, b) * 2;
	std::cout << '\n';
}