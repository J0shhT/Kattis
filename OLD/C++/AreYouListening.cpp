#include <iostream>
#include <vector>
#include <algorithm>

int x, y;

struct ListeningDevice
{
	int x;
	int y;
	int r;
};

bool sortDevicesToClosest(ListeningDevice l1, ListeningDevice l2)
{
	int d1 = (int)sqrt((abs(l1.x - x) * abs(l1.x - x)) + (abs(l1.y - y) * abs(l1.y - y))) - l1.r;
	int d2 = (int)sqrt((abs(l2.x - x) * abs(l2.x - x)) + (abs(l2.y - y) * abs(l2.y - y))) - l2.r;
	return d1 < d2;
}

int main()
{
	int n;
	std::cin >> x >> y >> n;

	std::vector<ListeningDevice> listeningDevices;
	listeningDevices.reserve(n);

	for (int i = 0; i < n; i++)
	{
		int lx, ly, lr;
		std::cin >> lx >> ly >> lr;
		listeningDevices.push_back({ lx, ly, lr });
	}

	std::sort(listeningDevices.begin(), listeningDevices.end(), sortDevicesToClosest);

	ListeningDevice ld = *(listeningDevices.begin() + 2);
	int maxRadius = (int)sqrt((abs(ld.x - x) * abs(ld.x - x)) + (abs(ld.y - y) * abs(ld.y - y))) - ld.r;

	std::cout << maxRadius << "\n";
}