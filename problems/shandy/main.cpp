#include <iostream>

int main()
{
	int B, L;
	std::cin >> B >> L;
	std::cout << std::min<int>(B, L) * 2 << std::endl;
}