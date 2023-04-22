#include <cmath>
#include <iostream>

int main()
{
	int N, M;
	std::cin >> N >> M;

	if (M % N == 0)
	{
		int count = std::round((double)M / N);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < count; ++j)
				std::cout << '*';
			std::cout << std::endl;
		}
		return 0;
	}

	double ratio = (double)M / N;
	int high = std::ceil(ratio);
	int low = std::floor(ratio);

	int highCount = std::round((ratio - low) * N);
	for (int i = 0; i < highCount; ++i)
	{
		for (int j = 0; j < high; ++j)
			std::cout << '*';
		std::cout << std::endl;
	}

	int lowCount = std::round((high - ratio) * N);
	for (int i = 0; i < lowCount; ++i)
	{
		for (int j = 0; j < low; ++j)
			std::cout << '*';
		std::cout << std::endl;
	}
}