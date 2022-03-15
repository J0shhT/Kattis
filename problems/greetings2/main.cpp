#include <iostream>
#include <cstdio>

int main()
{
	int count = 0;
	char c;
	while (c != EOF)
	{
		c = std::getchar();
		if (c == 'e')
			++count;
	}
	count*=2;
	std::cout << 'h';
	while (count-- > 0)
	{
		std::cout << 'e';
	}
	std::cout << 'y' << std::endl;
}