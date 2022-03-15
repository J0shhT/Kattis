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
	int n;
	std::cin >> n;
	while (n % sumDigits(n) != 0) ++n;
	std::cout << n << std::endl;
	return 0;
}