#include <iostream>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;
	int n = std::min<int>(std::min<int>(a, b), c);
	if (n == a)
		std::cout << "Monnei";
	else if (n == b)
		std::cout << "Fjee";
	else
		std::cout << "Dolladollabilljoll";
	std::cout << std::endl;
}