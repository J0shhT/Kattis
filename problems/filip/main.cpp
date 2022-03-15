#include <cstdio>

int main()
{
	char a[4], b[4] = { 0 };
	scanf("%3s %3s", a, b);

	char *c = NULL;
	for (int i = 2; i >= 0; --i)
	{
		if (c)
		{
			printf("%c", c[i]);
			continue;
		}
		if (a[i] == b[i])
		{
			printf("%c", a[i]);
			continue;
		}

		if (a[i] > b[i])
			c = a;
		else
			c = b;

		printf("%c", c[i]);
	}
	puts("");
	
	return 0;
}