#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int R, C, ZR, ZC;
	std::cin >> R >> C >> ZR >> ZC;
	std::cin.ignore();

	std::string s;
	s.reserve(C);
	std::string y;
	y.reserve(C * ZC);
	while (R-- > 0)
	{
		y.clear();
		std::cin >> s;
		if (ZC > 1)
			for (auto i = 0; i < s.length(); ++i)
				for (auto j = 0; j < ZC; ++j)
					y.push_back(s[i]);
		else
			y.append(s);

		for (auto i = 0; i < ZR; ++i)
			std::cout << y << '\n';
	}
}