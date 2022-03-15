#include <iostream>

int main()
{
	int width, n;
	std::cin >> width >> n;
	int area = 0;
	while (n-- > 0)
	{
		int w, l;
		std::cin >> w >> l;
		area += w*l;
	}
	std::cout << area/width << std::endl;
}