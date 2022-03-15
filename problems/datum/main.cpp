#include <iostream>
#include <ctime>

int main()
{
	static const char *weekdays[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	
	tm t;
	t.tm_sec = 0;
	t.tm_min = 0;
	t.tm_hour = 0;
	std::cin >> t.tm_mday;
	std::cin >> t.tm_mon;
	t.tm_year = 2009 - 1900;
	t.tm_isdst = 0;
	--(t.tm_mon);
	std::mktime(&t);

	std::cout << weekdays[t.tm_wday] << std::endl;
	return 0;
}