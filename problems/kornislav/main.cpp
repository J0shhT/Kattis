#include <algorithm>
#include <array>
#include <iostream>

int main()
{
	std::array<int, 4> edges;
	std::cin >> edges[0] >> edges[1] >> edges[2] >> edges[3];
	std::sort(edges.begin(), edges.end());
	std::cout << edges[0] * edges[2] << '\n';
}