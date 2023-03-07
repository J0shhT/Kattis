#include <algorithm>
#include <iostream>
#include <string>

int main()
{
	std::string s1, s2;
	std::cin >> s1 >> s2;
	std::string s3 = s1 + s2;
	std::transform(s3.begin(), s3.end(), s3.begin(), [](char c) { return std::tolower(c); });
	std::sort(s3.begin(), s3.end());
	std::cout << s3 << std::endl;
}