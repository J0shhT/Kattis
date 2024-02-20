#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::cin.ignore();

	std::string result;
	std::string word;
	while (std::cin >> word)
	{
		const auto& ch = word[0];
		if (ch >= 'A' && ch <= 'Z')
			result.push_back(ch);
	}
	std::cout << result << std::endl;
}