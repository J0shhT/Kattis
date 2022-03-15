#include <iostream> 
#include <cmath>

int main()
{
	unsigned int N;
	std::cin >> N;
	unsigned int x = pow(2u, N);
	std::cout << (1u + x) * (1u + x);
	return 0;
}