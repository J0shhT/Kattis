#include <iostream>

#define max(a, b) (a >= b ? a : b)

int main()
{
	int n, h, v;
	std::cin >> n >> h >> v;
	std::cout << max(n-h, (n-(n-h))) * max(n-v, (n-(n-v))) * 4 << std::endl;
	return 0;
}