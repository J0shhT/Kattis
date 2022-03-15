#include <iostream>

#define blocksRequired(h) ((2*(h)-1)*(2*(h)-1))

int main()
{
	int N;
	std::cin >> N;
	int height = 0;
	for (int blocks = 0; blocks = blocksRequired(height+1), N >= blocks; N -= blocks, ++height);
	std::cout << height << std::endl;
	return 0;
}

/*
	(2*1 - 1)^2 = 1
	(2*2 - 1)^2 = 9
	(2*3 - 1)^2 = 25
	(2*4 - 1)^2 = 49
*/