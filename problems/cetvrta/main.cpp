#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> xArray;
	std::vector<int> yArray;
	for (int i = 0; i < 3; ++i)
	{
		int x, y;
		std::cin >> x >> y;
		xArray.push_back(x);
		yArray.push_back(y);
	}
	std::sort(xArray.begin(), xArray.end());
	std::sort(yArray.begin(), yArray.end());
	if (xArray[0] == xArray[1])
		std::cout << xArray[2];
	else
		std::cout << xArray[0];
	std::cout << ' ';
	if (yArray[0] == yArray[1])
		std::cout << yArray[2];
	else
		std::cout << yArray[0];
	std::cout << std::endl;
	return 0;
}