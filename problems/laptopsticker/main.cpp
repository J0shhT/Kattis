#include <iostream>

int main()
{
	int wc, hc, ws, hs;
	std::cin >> wc >> hc >> ws >> hs;
	if (ws+1 < wc && hs+1 < hc)
		std::cout << 1;
	else
		std::cout << 0;
	std::cout << std::endl;
	return 0;
}