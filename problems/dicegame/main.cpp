#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <unordered_map>

static constexpr bool approximately(float a, float b)
{
	constexpr float epsilon = std::numeric_limits<float>::denorm_min() != 0 ? std::numeric_limits<float>::denorm_min()
																			: std::numeric_limits<float>::min();
	return std::abs(b - a) < std::max<float>(1e-6f * std::max<float>(std::abs(a), std::abs(b)), epsilon * 8);
}

class DiceDescriptor
{
	struct Die
	{
		Die(std::istream& is)
		{
			is >> min >> max;
		}

		int faces() const
		{
			return max - min + 1;
		}

		int min;
		int max;
	};

public:
	DiceDescriptor(std::istream& is)
		: d1(is)
		, d2(is)
		, total(d1.faces() * d2.faces())
		, sums()
	{
		sums.reserve(total);
		for (auto i = d1.min; i <= d1.max; ++i)
			for (auto j = d2.min; j <= d2.max; ++j)
				++sums[i + j];
	}

	float strength() const
	{
		float sum = 0.0f;
		for (const auto& kvp : sums)
			sum += (float)kvp.first * ((float)kvp.second / (float)total);
		return sum;
	}

private:
	Die d1;
	Die d2;
	const int total;
	std::unordered_map<int, int> sums;
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	DiceDescriptor gunnar(std::cin);
	DiceDescriptor emma(std::cin);
	float s1 = gunnar.strength();
	float s2 = emma.strength();
	if (approximately(s1, s2))
		std::cout << "Tie";
	else if (s1 > s2)
		std::cout << "Gunnar";
	else
		std::cout << "Emma";
	std::cout << std::endl;
}