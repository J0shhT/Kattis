#include <cmath>
#include <iostream>
#include <vector>

class Target
{
protected:
	explicit Target() = default;

public:
	virtual bool Contains(int x, int y) const = 0;
};

class RectangleTarget : public Target
{
public:
	explicit RectangleTarget()
	{
		std::cin >> x1 >> y1 >> x2 >> y2;
	}

	virtual bool Contains(int x, int y) const override
	{
		return x >= x1 && x <= x2 && y >= y1 && y <= y2;
	}

private:
	int x1;
	int y1;
	int x2;
	int y2;
};

class CircleTarget : public Target
{
public:
	explicit CircleTarget()
	{
		std::cin >> x >> y >> r;
	}

	virtual bool Contains(int x, int y) const override
	{
		return sqrt(pow(x - this->x, 2) + pow(y - this->y, 2)) <= r;
	}

private:
	int x;
	int y;
	int r;
};

int main()
{
	std::vector<Target*> targets;

	int m;
	std::cin >> m;
	while (m--)
	{
		std::string shape;
		std::cin >> shape;
		if (shape == "rectangle")
			targets.push_back(new RectangleTarget());
		else if (shape == "circle")
			targets.push_back(new CircleTarget());
	}

	int n;
	std::cin >> n;
	while (n--)
	{
		int x, y;
		std::cin >> x >> y;

		int hits = 0;
		for (auto target : targets)
			if (target->Contains(x, y))
				++hits;

		std::cout << hits << std::endl;
	}
}