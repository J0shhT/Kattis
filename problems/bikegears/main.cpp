#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

std::ostream& operator<<(std::ostream& os, const class Gear& gear);

struct Gear
{
	int64_t f;
	int64_t b;

	Gear(int64_t f, int64_t b)
		: f(f)
		, b(b)
	{
	}

	double ratio() const
	{
		return (double)f / (double)b;
	}

	static bool compareTo(const Gear& first, const Gear& second)
	{
		// a/b == c/d is the same as a*d == c*b
		int64_t x = first.f * second.b;
		int64_t y = second.f * first.b;
		if (x == y)
			return first.f < second.f;
		return x < y;
	}
};

std::ostream& operator<<(std::ostream& os, const Gear& gear)
{
	os << '(' << gear.f << ',' << gear.b;
	os << ')';
	// os << ' ' << gear.ratio();
	return os;
}

int main()
{
	int F, B;
	std::cin >> F >> B;

	std::vector<int64_t> fTeeth;
	fTeeth.reserve(F);
	for (size_t i = 0; i < F; ++i)
	{
		int64_t f;
		std::cin >> f;
		fTeeth.push_back(f);
	}

	std::vector<int64_t> bTeeth;
	bTeeth.reserve(B);
	for (size_t i = 0; i < B; ++i)
	{
		int64_t b;
		std::cin >> b;
		bTeeth.push_back(b);
	}

	std::vector<Gear> gears;
	for (size_t i = 0; i < F; ++i)
	{
		for (size_t j = 0; j < B; ++j)
			gears.emplace_back(fTeeth[i], bTeeth[j]);
	}

	std::sort(gears.begin(), gears.end(), Gear::compareTo);

	for (const Gear& gear : gears)
	{
		std::cout << gear << '\n';
	}
}