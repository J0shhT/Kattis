#include <iostream>

int main()
{
	int N, P, S;
	std::cin >> N >> P >> S;

	bool* cards = new bool[N + 1];
	for (size_t i = 1; i <= N; ++i)
		cards[i] = true;

	while (S-- > 0)
	{
		int m;
		std::cin >> m;

		bool hasSecret = false;
		int* chosen = new int[m];
		for (size_t i = 0; i < m; ++i)
		{
			std::cin >> chosen[i];
			if (chosen[i] == P)
				hasSecret = true;
		}

		if (hasSecret)
		{
			std::cout << "KEEP";
			for (size_t i = 1; i <= N; ++i)
				cards[i] = false;
			for (size_t i = 0; i < m; ++i)
				cards[chosen[i]] = true;
		}
		else
		{
			std::cout << "REMOVE";
			for (size_t i = 0; i < m; ++i)
				cards[chosen[i]] = false;
		}

		std::cout << '\n';
		delete[] chosen;
	}

	delete[] cards;
}