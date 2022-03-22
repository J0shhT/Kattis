#include <iostream>

int main()
{
	int G, S, C;
	std::cin >> G >> S >> C;
	int power = G * 3 + S * 2 + C;

	if (power >= 2)
	{
		if (power >= 8)
			std::cout << "Province";
		else if (power >= 5)
			std::cout << "Duchy";
		else
			std::cout << "Estate";
		std::cout << " or ";
	}

	if (power >= 6)
		std::cout << "Gold";
	else if (power >= 3)
		std::cout << "Silver";
	else
		std::cout << "Copper";

	std::cout << '\n';
}