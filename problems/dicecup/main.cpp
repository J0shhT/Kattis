#include <cstdio>

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	size_t *sums = new size_t[N+M+1];
	for (size_t i = 0; i < N+M+1; ++i)
		sums[i] = 0;

	size_t highest = 0;
	for (size_t i = 1; i <= N; ++i)
	{
		for (size_t j = 1; j <= M; ++j)
		{
			size_t sum = i+j;
			++sums[sum];
			if (sums[sum] > highest)
				highest = sums[sum];
		}
	}

	for (size_t i = 2; i < N+M; ++i)
	{
		if (sums[i] == highest)
			printf("%d\n", i);
	}

	delete[] sums;
	return 0;
}