#include <iostream>

int main()
{
	int C;
	std::cin >> C;
	while (C-- > 0)
	{
		int N;
		std::cin >> N;
		int* grades = new int[N];

		double average = 0;
		for (int i = 0; i < N; ++i)
		{
			int grade;
			std::cin >> grade;
			grades[i] = grade;
			average += grade;
		}
		average /= N;

		int count = 0;
		for (int i = 0; i < N; ++i)
		{
			if (grades[i] > average)
				++count;
		}

		std::printf("%.3f%%\n", (double(count) / double(N)) * 100);
		delete[] grades;
	}
}