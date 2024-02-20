#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	char ch;
	std::cin >> ch;
	if (ch == 'Y')
		std::cout << "Kannski";
	else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
		std::cout << "Jebb";
	else
		std::cout << "Neibb";
	std::cout << std::endl;
}