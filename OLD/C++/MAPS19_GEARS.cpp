#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <vector>
#include <map>

struct Ratio
{
	double ratio;
	int f;
	int b;
};

bool SortRatio(Ratio rhs, Ratio lhs)
{
	if (rhs.f < lhs.f)
	{
		return true;
	}
	else if (rhs.f == lhs.f)
	{
		if (rhs.b > lhs.b)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int main()
{
	int F, B;
	std::cin >> F >> B;

	std::vector<int> fTeeth;
	fTeeth.reserve(F);
	std::vector<int> bTeeth;
	bTeeth.reserve(B);

	for (int i = 0; i < F; i++)
	{
		int teeth;
		std::cin >> teeth;
		fTeeth.push_back(teeth);
	}
	for (int i = 0; i < B; i++)
	{
		int teeth;
		std::cin >> teeth;
		bTeeth.push_back(teeth);
	}

	std::vector<Ratio> gearRatios;

	for (int f : fTeeth)
	{
		for (int b : bTeeth)
		{
			gearRatios.push_back({ (double)f / (double)b, f, b });
		}
	}

	std::sort(gearRatios.begin(), gearRatios.end(), SortRatio);

	for (Ratio ratio : gearRatios)
	{
		std::cout << "(" << ratio.f << "," << ratio.b << ")\n";
	}
	system("pause");
}