#include <iostream>
#include <string>
#include <unordered_map>

int getMonth(const std::string& name)
{
	static const std::unordered_map<std::string, int> months = {{"Jan", 1}, {"Feb", 2},  {"Mar", 3},  {"Apr", 4},
																{"May", 5}, {"Jun", 6},  {"Jul", 7},  {"Aug", 8},
																{"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};
	return months.find(name)->second;
}

std::string astrologicalSign(int month, int day)
{
	if ((month == 1 && day >= 21) || (month == 2 && day <= 19))
		return "Aquarius";
	else if ((month == 2 && day >= 20) || (month == 3 && day <= 20))
		return "Pisces";
	else if ((month == 3 && day >= 21) || (month == 4 && day <= 20))
		return "Aries";
	else if ((month == 4 && day >= 21) || (month == 5 && day <= 20))
		return "Taurus";
	else if ((month == 5 && day >= 21) || (month == 6 && day <= 21))
		return "Gemini";
	else if ((month == 6 && day >= 22) || (month == 7 && day <= 22))
		return "Cancer";
	else if ((month == 7 && day >= 23) || (month == 8 && day <= 22))
		return "Leo";
	else if ((month == 8 && day >= 23) || (month == 9 && day <= 21))
		return "Virgo";
	else if ((month == 9 && day >= 22) || (month == 10 && day <= 22))
		return "Libra";
	else if ((month == 10 && day >= 23) || (month == 11 && day <= 22))
		return "Scorpio";
	else if ((month == 11 && day >= 23) || (month == 12 && day <= 21))
		return "Sagittarius";
	else if ((month == 12 && day >= 22) || (month == 1 && day <= 20))
		return "Capricorn";
	else
		std::abort();
}

int main()
{
	int N;
	std::cin >> N;
	while (N-- > 0)
	{
		int day;
		std::string month;
		std::cin >> day >> month;
		std::cout << astrologicalSign(getMonth(month), day) << '\n';
	}
}