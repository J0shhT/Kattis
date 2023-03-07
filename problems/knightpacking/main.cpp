#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	std::cout << (n % 2 ? "first" : "second") << '\n';
}