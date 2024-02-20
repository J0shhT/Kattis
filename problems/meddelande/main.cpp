#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N, M;
	std::cin >> N >> M;
	std::string message;
	std::string line;
	while (std::cin >> line)
		for (const auto& ch : line)
			if (ch != '.')
				message.push_back(ch);
	std::cout << message << std::endl;
}