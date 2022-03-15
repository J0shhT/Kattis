#include <cstdio>
#include <cmath>
#include <cstdlib>

int main()
{
	int N, Q;
	scanf("%d %d", &N, &Q);

	int *locations = new int[N];
	for (int i = 0; i < N; ++i)
		scanf("%d", locations+i);

	while (Q--)
	{
		int query;
		scanf("%d", &query);
		if (query == 1)
		{
			int C, X;
			scanf("%d %d", &C, &X);
			locations[C-1] = X;
		}
		else
		{
			int A, B;
			scanf("%d %d", &A, &B);
			printf("%d\n", abs(locations[A-1] - locations[B-1]));
		}
	}

	delete[] locations;
	return 0;
}