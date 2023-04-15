#include <iomanip>
#include <iostream>
#include <string>

int main()
{
	std::string s;
	double c;
	std::cin >> s >> c;
	std::cout << std::setprecision(18) << std::min<double>(c, s.length()) << std::endl;
}