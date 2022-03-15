#include <iostream>

int main()
{
	int n, d;
	std::cin >> n >> d;
	while (n != 0 || d != 0)
	{
		std::cout << n / d << ' ' << n % d << " / " << d << '\n';
		std::cin >> n >> d;
	}
	return 0;
}