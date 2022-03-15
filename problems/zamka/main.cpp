#include <iostream>

int sumDigits(int num)
{
	int sum = 0;
	while (num > 0)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

int main()
{
	int L, D, X;
	std::cin >> L >> D >> X;
	int N = D;
	int M = L;
	for (int i = L; i <= D; ++i)
	{
		int sum = sumDigits(i);
		if (sum != X) continue;
		if (i > M) M = i;
		if (i < N) N = i;
	}
	std::cout << N << std::endl << M << std::endl;
	return 0;
}