#include <cmath>
#include <iostream>
#include <limits>

class Matrix2x2
{
public:
	explicit Matrix2x2(int a, int b, int c, int d)
		: a(a)
		, b(b)
		, c(c)
		, d(d)
	{
	}

	explicit Matrix2x2(std::istream& input)
	{
		input >> a >> b >> c >> d;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	Matrix2x2 Inverse() const
	{
		return Matrix2x2(d, -b, -c, a) * (1.0f / (a * d - b * c));
	}

	Matrix2x2 operator*(float value)
	{
		return Matrix2x2(a * value, b * value, c * value, d * value);
	}

	void Print(std::ostream& output) const
	{
		output << a << ' ' << b << '\n' << c << ' ' << d << std::endl;
	}

private:
	int a;
	int b;
	int c;
	int d;
};

int main()
{
	int i = 0;
	while (std::cin.good())
	{
		++i;
		Matrix2x2 matrix(std::cin);

		if (std::getchar() == -1) // hack
			break;

		std::cout << "Case " << i << ':' << '\n';
		auto inverse = matrix.Inverse();
		inverse.Print(std::cout);
	}
}