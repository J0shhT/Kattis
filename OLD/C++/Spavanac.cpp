#include <iostream>
#include <cmath>

int main()
{
	int h, m;
	std::cin >> h;
	std::cin >> m;

	h = (m >= 45 ? h : h - 1);
	h = (h >= 0 ? h : 24 + h);
	m -= 45;
	m = (m >= 0 ? m : 60 + m);

	std::cout << h << " " << m << "\n";
	return 0;
}