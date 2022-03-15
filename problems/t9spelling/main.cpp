#include <iostream>
#include <string>

int main()
{
	const char* SEQUENCES[] = {
		"2", "22", "222",		"3", "33", "333",			"4", "44", "444",
		"5", "55", "555",		"6", "66", "666",			"7", "77", "777", "7777",
		"8", "88", "888",		"9", "99", "999", "9999"
	};
	int n;
	std::cin >> n;
	std::getchar();
	for (int i = 1; i <= n; ++i)
	{
		std::string message;
		std::getline(std::cin, message);
		std::cout << "Case #" << i << ": ";
		char seqlast = 0;
		for (char c : message)
		{
			char seqcur = 0;
			if (c >= 'a' && c <= 'z')
				seqcur = SEQUENCES[c-'a'][0];
			else
				seqcur = '0';
			if (seqcur == seqlast)
				std::cout << " ";
			if (seqcur == '0')
				std::cout << "0";
			else
				std::cout << SEQUENCES[c-'a'];
			seqlast = seqcur;
		}
		std::cout << std::endl;
	}
}