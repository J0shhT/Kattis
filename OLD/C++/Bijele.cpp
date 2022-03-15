#include <iostream>

int main()
{
	int desiredPieces[6] = { 1, 1, 2, 2, 2, 8 };
	for (int i = 0; i < 6; i++)
	{
		int pieces;
		std::cin >> pieces;
		std::cout << desiredPieces[i] - pieces << " ";
	}
}