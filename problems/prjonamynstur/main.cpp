#include <iostream>
#include <string>

static constexpr int cost(char ch)
{
	switch (ch)
	{
	case '.':
		return 20;
	case 'O':
		return 10;
	case '\\':
	case '/':
		return 25;
	case 'A':
		return 35;
	case '^':
		return 5;
	case 'v':
		return 22;
	default:
		return 0;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	std::cin.ignore();

	int price = 0;
	std::string line;
	while (std::cin >> line)
		for (const auto& ch : line)
			price += cost(ch);
	std::cout << price << std::endl;
}