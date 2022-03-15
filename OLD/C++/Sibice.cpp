#include <iostream>
#include <cmath>

int main()
{
	int n, w, h;
	std::cin >> n;
	std::cin >> w;
	std::cin >> h;
	for (int i = 0; i < n; i++)
	{
		int l;
		std::cin >> l;
		std::cout << (l <= sqrt(w*w + h*h) ? "DA" : "NE") << "\n";
	}
	return 0;
}