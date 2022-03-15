#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int main()
{
	int N;
	std::cin >> N;

	for (; N > 0; --N)
	{
		long long base10 = 0;
		std::string base60;
		std::vector<std::string> base60Numbers;

		std::string tablet;
		std::cin >> tablet;

		bool wasSeperator = false;
		for (auto iter = tablet.begin(); iter != tablet.end(); ++iter)
		{
			if (*iter == ',')
			{
				if (wasSeperator)
				{
					base60Numbers.push_back("0");
					base60 = "";
				}
				else
				{
					base60Numbers.push_back(base60);
					base60 = "";
				}
				wasSeperator = true;
			}
			else
			{
				base60 += *iter;
				wasSeperator = false;
			}
		}
		if (base60.size() == 0)
		{
			base60Numbers.push_back("0");
		}
		else
		{
			base60Numbers.push_back(base60);
			base60 = "";
		}

		for (int i = 0; i < base60Numbers.size(); i++)
		{
			base10 += std::stoi(base60Numbers[base60Numbers.size() - i - 1]) * pow(60, i);
		}

		std::cout << base10 << "\n";
	}
}