#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>

int main()
{
	int n = 0;
	bool firstTime = true;
	for(std::cin >> n; n != 0; std::cin >> n)
	{
		if (!firstTime) std::cout << '\n';
		std::vector<std::string> names;
		names.reserve(n);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < n; ++i)
		{
			std::string name;
			std::getline(std::cin, name);
			names.push_back(name);
		}
		std::stable_sort(names.begin(), names.end(), [](const std::string &name1, const std::string &name2) -> bool {
			if (name1[0] == name2[0])
				return name1[1] < name2[1];
			else
				return name1[0] < name2[0];	
		});
		for (const std::string &name : names)
		{
			std::cout << name << '\n';
		}
		firstTime = false;
	}
	return 0;
}