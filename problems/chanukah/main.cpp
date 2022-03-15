#include <cstdio>

int main()
{
	int P;
	scanf("%d", &P);
	while (P-->0)
	{
		int K, N;
		scanf("%d %d", &K, &N);
		int sum = N;
		for (int i = 1; i <= N; ++i)
		{
			sum += i;
		}
		printf("%d %d\n", K, sum);
	}
	return 0;
}