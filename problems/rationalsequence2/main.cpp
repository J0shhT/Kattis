#include <iostream>
#include <string>
#include <cmath>

struct Node
{
	int p; // numerator
	int q; // denominator
	Node(int p, int q) : p(p), q(q) {}

	bool isLeft() const { return p < q; }
	bool isRight() const { return p > q; }
	operator bool() const { return p != q; }

	Node getParent() const
	{
		if (isRight())
			return Node(p - q, q);
		else
			return Node(p, q - p);
	}
};

int main()
{
	int P;
	std::cin >> P;
	while (P-- > 0)
	{
		int K, p, q;
		std::cin >> K;
		std::scanf("%d/%d", &p, &q);

		int height = 0;
		int offset = 0;
		Node current(p, q);
		while (current)
		{
			++height;
			if (current.isRight())
				offset += std::pow(2, height - 1);
			current = current.getParent();
		}

		int index = std::pow(2, height) + offset;
		std::cout << K << ' ' << index << '\n';
	}
	return 0;
}