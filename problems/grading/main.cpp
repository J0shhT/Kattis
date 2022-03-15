#include <iostream>

int main()
{
	int a, b, c, d, e, grade;
	std::cin >> a >> b >> c >> d >> e >> grade;
	if (grade >= a) std::cout << 'A';
	else if (grade >= b) std::cout << 'B';
	else if (grade >= c) std::cout << 'C';
	else if (grade >= d) std::cout << 'D';
	else if (grade >= e) std::cout << 'E';
	else std::cout << 'F';
	std::cout << std::endl;
	return 0;
}