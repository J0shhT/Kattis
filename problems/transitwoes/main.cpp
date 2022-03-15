#include <iostream>

int main()
{
	int s, t, n;
	std::cin >> s >> t >> n;

	int *d = new int[n+1];
	for (int i = 0; i <= n; ++i)
		std::cin >> d[i];

	int *b = new int[n];
	for (int i = 0; i < n; ++i)
		std::cin >> b[i];

	int *c = new int[n];
	for (int i = 0; i < n; ++i)
		std::cin >> c[i];

	s += d[0]; // walk from house to first bus
	for (int i = 0; i < n; ++i)
	{
		if (s % c[i] != 0) // do we have to wait for the bus?
			s += c[i] - (s % c[i]);
		s += b[i]; // ride the bus
	}
	s += d[n]; // walk from last bus to class

	if (s <= t)
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;

	delete[] c;
	delete[] b;
	delete[] d;
	return 0;
}