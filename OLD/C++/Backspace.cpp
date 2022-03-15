#include <iostream>
#include <string>

int main()
{
	std::string text;
	std::cin >> text;

	auto iter = text.begin();
	while (iter != text.end())
	{
		if (*iter == '<')
		{
			iter = text.erase(iter - 1, iter + 1);
		}
		else
		{
			iter++;
		}
	}
	std::cout << text << "\n";

	system("pause");
}