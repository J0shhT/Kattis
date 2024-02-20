#include <iostream>

static void drawHorizontal(int size)
{
	std::cout << '+';
	while (size-- > 0)
		std::cout << '-';
	std::cout << '+' << '\n';
}

static void drawVertical(int size)
{
	std::cout << '|';
	while (size-- > 0)
		std::cout << ' ';
	std::cout << '|' << '\n';
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N;
	std::cin >> N;
	drawHorizontal(N);
	for (auto i = 0; i < N; ++i)
		drawVertical(N);
	drawHorizontal(N);
}