#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int v, n;
	std::cin >> v >> n;
	std::string s;
	int k;
	while (n-- > 0)
	{
		std::cin >> s >> k;
		std::cout << s << ' ';
		if (k < v)
			std::cout << "lokud\n";
		else
			std::cout << "opin\n";
	}
}