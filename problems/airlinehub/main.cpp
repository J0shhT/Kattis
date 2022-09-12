#define _USE_MATH_DEFINES

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

static constexpr double toRadians(double angle)
{
	double rad = angle * (M_PI / 180.0);
	while (rad < 0)
		rad += (M_PI * 2);
	return rad;
}

struct GeoPoint
{
	double latitude;
	double longitude;

	GeoPoint()
		: latitude(0.0)
		, longitude(0.0)
	{
	}

	GeoPoint(double latitude, double longitude)
		: latitude(latitude)
		, longitude(longitude)
	{
	}

	bool operator==(const GeoPoint& other) const
	{
		return latitude == other.latitude && longitude == other.longitude;
	}

	double distanceTo(const GeoPoint& other) const
	{
		static const double R = 6372.797560856;
		double lat1 = toRadians(latitude);
		double lat2 = toRadians(other.latitude);
		double dlat = toRadians(other.latitude - latitude);
		double dlon = toRadians(other.longitude - longitude);

		double sin2_lat = sin(dlat * 0.5) * sin(dlat * 0.5);
		double sin2_lon = sin(dlon * 0.5) * sin(dlon * 0.5);
		double cos_lat = cos(lat1) * cos(lat2);

		return 2.0 * R * asin(sqrt(sin2_lat + cos_lat * sin2_lon));
	}
};

// std::ostream& operator<<(std::ostream& os, const GeoPoint& point)
// {
//  os << '[' << point.latitude << ' ' << point.longitude << ']';
//  return os;
// }

int main()
{
	int n;
	while (std::cin >> n, !std::cin.eof())
	{
		std::vector<GeoPoint> points;
		double minMaxDistance = std::numeric_limits<double>::max();
		GeoPoint hubPoint;

		while (n-- > 0)
		{
			double latitude, longitude;
			std::cin >> latitude >> longitude;
			points.emplace_back(latitude, longitude);
		}

		for (GeoPoint point1 : points)
		{
			double maxDistance = 0;
			for (GeoPoint point2 : points)
			{
				if (point1 == point2)
					continue;
				maxDistance = std::max(maxDistance, point1.distanceTo(point2));
			}
			if (maxDistance < minMaxDistance)
			{
				minMaxDistance = maxDistance;
				hubPoint = point1;
			}
		}

		std::printf("%.2lf %.2lf\n", hubPoint.latitude, hubPoint.longitude);
	}
}