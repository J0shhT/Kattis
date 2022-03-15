#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

const int WIDTH = 30;
const int HEIGHT = 15;

struct Pixel
{
	int x;
	int y;
};

struct Point
{
	double x;
	double y;
};

typedef std::vector<Pixel> Touch;
typedef std::vector<Pixel> Grip;

class ClusterLabelAlgorithm
{
	public:
		ClusterLabelAlgorithm(std::vector<std::vector<bool>> data)
		{
			m_Data = data;

			LabelClusters();
		}

		std::map<int, std::map<int, int>> GetLabels() const
		{
			return m_Labels;
		}

	private:

		void LabelClusters()
		{
			int n_rows = m_Data.size();
			int n_columns = m_Data[0].size();
			int largestLabel = 0;

			//Pass 1
			for (int y = 0; y < n_rows; y++)
			{
				for (int x = 0; x < n_columns; x++)
				{
					bool current = m_Data[y][x];

					if (!current)
					{
						SetLabel(x, y, 0);
						continue;
					}

					int currentLabel = GetLabel(x, y);

					bool left = false;
					int leftLabel = 0;
					bool top = false;
					int topLabel = 0;

					if (x > 0)
					{
						left = m_Data[y][x - 1];
						leftLabel = GetLabel(x - 1, y);
					}
					if (y > 0)
					{
						top = m_Data[y - 1][x];
						topLabel = GetLabel(x, y - 1);
					}
					
					if (x > 0 && left == current)
					{
						//Left pixel is same
						//Assign same label to current
						SetLabel(x, y, leftLabel);
					}

					if (x > 0 && y > 0 && left == current && top == current && leftLabel != topLabel)
					{
						//Left pixel and top pixel is same, but not the same labels
						//Assign minimum label to current pixel, record label equivalence
						SetLabel(x, y, std::min(leftLabel, topLabel));
						SetEquivelance(std::max(leftLabel, topLabel), std::min(leftLabel, topLabel));
					}
					else if (x > 0 && y > 0 && left != current && top == current)
					{
						//Left pixel is different but top pixel is same
						//Assign label of top pixel to current pixel label
						SetLabel(x, y, topLabel);
					}
					else if ((x == 0 || y == 0) || (left != current && top != current))
					{
						//Left pixel and top pixel is different
						//Create new label and assign it to current pixel
						SetLabel(x, y, ++largestLabel);
					}
				}
			}

			//Pass 2
			for (int y = 0; y < n_rows; y++)
			{
				for (int x = 0; x < n_columns; x++)
				{
					//Set current pixel label to lowest equivalent label
					int currentLabel = GetLabel(x, y);
					SetLabel(x, y, GetEquivelance(currentLabel));
				}
			}
		}

		int GetLabel(int x, int y)
		{
			if (m_Labels.find(y) != m_Labels.end())
			{
				if (m_Labels[y].find(x) != m_Labels[y].end())
				{
					return m_Labels[y][x];
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}

		void SetLabel(int x, int y, int label)
		{
			if (m_Labels.find(y) == m_Labels.end())
			{
				m_Labels.emplace(y, std::map<int, int>());
				if (m_Labels[y].find(x) == m_Labels[y].end())
				{
					m_Labels[y].emplace(x, label);
					return;
				}
			}
			m_Labels[y][x] = label;
		}

		void SetEquivelance(int label, int equivalent)
		{
			if (m_Equivalents.find(label) == m_Equivalents.end())
			{
				m_Equivalents.emplace(label, equivalent);
			}
			else
			{
				if (m_Equivalents[label] > equivalent)
				{
					m_Equivalents[label] = equivalent;
				}
			}
		}

		int GetEquivelance(int label)
		{
			if (m_Equivalents.find(label) != m_Equivalents.end())
			{
				return m_Equivalents[label];
			}
			else
			{
				return label;
			}
		}

		std::vector<std::vector<bool>> m_Data;
		std::map<int, std::map<int, int>> m_Labels;
		std::map<int, int> m_Equivalents;

};

class Image
{
	public:

		Image(std::vector<std::string> imageData)
		{
			for (std::string scanLine : imageData)
			{
				std::vector<bool> scanLineData;
				for (char pixel : scanLine)
				{
					if (pixel == '.')
					{
						scanLineData.push_back(false);
					}
					else if (pixel == 'X')
					{
						scanLineData.push_back(true);
					}
				}
				this->imageData.push_back(scanLineData);
			}
		}

		void print()
		{
			for (int y = 0; y < HEIGHT; y++)
			{
				for (int x = 0; x < WIDTH; x++)
				{
					if (imageData[y][x])
					{
						std::cout << 'X';
					}
					else
					{
						std::cout << '.';
					}
				}
				std::cout << '\n';
			}
		}

		bool isTouch(int x, int y) const
		{
			return this->imageData[y][x];
		}

		std::vector<Touch> getTouches()
		{
			ClusterLabelAlgorithm alg = ClusterLabelAlgorithm(this->imageData);
			std::map<int, Touch> touchGroupMap;
			for (auto yIter : alg.GetLabels())
			{
				int y = yIter.first;
				for (auto xIter : yIter.second)
				{
					int x = xIter.first;
					int label = xIter.second;
					if (touchGroupMap.find(label) == touchGroupMap.end())
					{
						touchGroupMap.emplace(label, Touch());
					}
					touchGroupMap[label].push_back({ x, y });
				}
			}

			std::vector<Touch> touchGroups;
			for (auto iter : touchGroupMap)
			{
				if (iter.first == 0)
					continue;

				touchGroups.push_back(iter.second);
			}

			return touchGroups;
		}

	private:

		std::vector<std::vector<bool>> imageData;
};

void printPoints(std::vector<Pixel> points)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			bool isTouchPoint = false;
			for (Pixel pixel : points)
			{
				if (pixel.x == x && pixel.y == y)
				{
					isTouchPoint = true;
					break;
				}
			}
			if (isTouchPoint)
			{
				std::cout << 'O';
			}
			else
			{
				std::cout << '.';
			}
		}
		std::cout << '\n';
	}
}

Pixel getTouchPoint(Touch touch)
{
	Pixel touchPoint = {0, 0};
	for (int i = 0; i < touch.size(); i++)
	{
		Pixel pixel = touch[i];
		touchPoint.x += pixel.x;
		touchPoint.y += pixel.y;
	}
	touchPoint.x /= touch.size();
	touchPoint.y /= touch.size();
	return touchPoint;
}

Pixel getGripPoint(Grip grip)
{
	Pixel gripPoint = { 0, 0 };
	for (Pixel pixel : grip)
	{
		gripPoint.x += pixel.x;
		gripPoint.y += pixel.y;
	}
	gripPoint.x /= grip.size();
	gripPoint.y /= grip.size();
	return gripPoint;
}

double getGripSpread(Grip grip, Pixel gripPoint)
{
	double spread = 0.0;
	for (Pixel pixel : grip)
	{
		double distance = sqrt(pow(abs(pixel.x - gripPoint.x), 2) + pow(abs(pixel.y - gripPoint.y), 2));
		spread += distance;
	}
	return spread / grip.size();
}

Point getIntersection(Pixel p1, Pixel p2, Pixel p3, Pixel p4)
{
	double x1 = p1.x;
	double y1 = p1.y;
	double x2 = p2.x;
	double y2 = p2.y;
	double x3 = p3.x;
	double y3 = p3.y;
	double x4 = p4.x;
	double y4 = p4.y;

	double px = ((x1*y2 - y1*x2)*(x3 - x4) - (x1 - x2)*(x3*y4 - y3*x4))
				/ ((x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4));
	double py = ((x1*y2 - y1*x2)*(y3 - y4) - (y1 - y2)*(x3*y4 - y3*x4))
				/ ((x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4));

	return { px, py };
}

double getTouchRotation(Pixel gripPoint1, Pixel touchPoint1, Pixel gripPoint2, Pixel touchPoint2)
{
	Point intersectPoint = getIntersection(gripPoint1, touchPoint1, gripPoint2, touchPoint2);

	double l1 = sqrt(pow(abs(touchPoint1.x - intersectPoint.x), 2) + pow(abs(touchPoint1.y - intersectPoint.y), 2));
	double l2 = sqrt(pow(abs(touchPoint2.x - intersectPoint.x), 2) + pow(abs(touchPoint2.y - intersectPoint.y), 2));
	double d = sqrt(pow(abs(touchPoint1.x - touchPoint2.x), 2) + pow(abs(touchPoint1.y - touchPoint2.y), 2));

	if (l1 == 0.0 || l2 == 0.0)
	{
		l1 = sqrt(pow(abs(gripPoint1.x - intersectPoint.x), 2) + pow(abs(gripPoint1.y - intersectPoint.y), 2));
		l2 = sqrt(pow(abs(gripPoint2.x - intersectPoint.x), 2) + pow(abs(gripPoint2.y - intersectPoint.y), 2));
		d = sqrt(pow(abs(gripPoint1.x - gripPoint2.x), 2) + pow(abs(gripPoint1.y - gripPoint2.y), 2));
	}

	double rot = acos(-((d*d - l1 * l1 - l2 * l2) / (2.0*l1*l2)));
	double rotDeg = rot * (180 / M_PI);

	return rot;
}

Pixel getCorrespondingTouchPoint(Pixel touchPoint, std::vector<Pixel> otherTouchPoints)
{
	Pixel correspondingTouchPoint = otherTouchPoints[0];
	double correspondingTouchPointDistance = pow(abs(otherTouchPoints[0].x - touchPoint.x), 2) + pow(abs(otherTouchPoints[0].y - touchPoint.y), 2);
	for (Pixel otherTouchPoint : otherTouchPoints)
	{
		double squareDistance = pow(abs(otherTouchPoint.x - touchPoint.x), 2) + pow(abs(otherTouchPoint.y - touchPoint.y), 2);
		if (squareDistance < correspondingTouchPointDistance)
		{
			correspondingTouchPoint = otherTouchPoint;
			correspondingTouchPointDistance = squareDistance;
		}
	}
	return correspondingTouchPoint;
}

double getGripRotation(Grip initialGrip, Pixel initialGripPoint, Grip finalGrip, Pixel finalGripPoint)
{
	double gripRotation = 0;
	for (Pixel touchPoint : initialGrip)
	{
		Pixel correspondingTouchPoint = getCorrespondingTouchPoint(touchPoint, finalGrip);
		gripRotation += getTouchRotation(initialGripPoint, touchPoint, finalGripPoint, correspondingTouchPoint);
	}
	return gripRotation / initialGrip.size();
}

struct Gesture
{
	Gesture(Grip initial, Grip final)
	{
		initialGrip = initial;
		finalGrip = final;
		initialGripPoint = getGripPoint(initial);
		finalGripPoint = getGripPoint(final);
	}

	double getPanDistance()
	{
		return sqrt(pow(finalGripPoint.x - initialGripPoint.x, 2) + pow(finalGripPoint.y - initialGripPoint.y, 2));
	}

	double getZoomDistance()
	{
		return getGripSpread(finalGrip, finalGripPoint) - getGripSpread(initialGrip, initialGripPoint);
	}

	double getRotationAngle()
	{
		return getGripRotation(initialGrip, initialGripPoint, finalGrip, finalGripPoint);
	}

	double getRotationDistance()
	{
		return getGripSpread(initialGrip, initialGripPoint) * getRotationAngle();
	}

	Grip initialGrip;
	Grip finalGrip;
	Pixel initialGripPoint;
	Pixel finalGripPoint;
};

int main()
{
	std::vector<std::string> imageData1;
	std::vector<std::string> imageData2;

	for (int i = 0; i < HEIGHT; i++)
	{
		std::string lineData1;
		std::string lineData2;
		std::cin >> lineData1;
		std::cin >> lineData2;
		imageData1.push_back(lineData1);
		imageData2.push_back(lineData2);
	}

	Image image1 = Image(imageData1);
	Image image2 = Image(imageData2);

	std::vector<Touch> image1Touches = image1.getTouches();
	std::vector<Touch> image2Touches = image2.getTouches();

	Grip image1Grip;
	for (Touch touch : image1Touches)
	{
		image1Grip.push_back(getTouchPoint(touch));
	}
	Grip image2Grip;
	for (Touch touch : image2Touches)
	{
		image2Grip.push_back(getTouchPoint(touch));
	}

	Gesture imageGesture = Gesture(image1Grip, image2Grip);


	//std::cout << "\n";
	//printPoints(image1Grip);

	std::vector<Pixel> image1GripPoints;
	image1GripPoints.push_back(getGripPoint(image1Grip));
	//std::cout << "\n";
	//printPoints(image1GripPoints);

	std::vector<Pixel> image2GripPoints;
	image2GripPoints.push_back(getGripPoint(image2Grip));
	//std::cout << "\n";
	//printPoints(image2GripPoints);

	int fingers = image1Touches.size();
	double panDistance = imageGesture.getPanDistance();
	double zoomDistance = imageGesture.getZoomDistance();
	double rotationAngle = imageGesture.getRotationAngle();
	double rotationDistance = imageGesture.getRotationDistance();


	/*std::cout << "\n";
	std::cout << "Touches: " << fingers << "\n";
	std::cout << "Pan Distance: " << panDistance << "\n";
	std::cout << "Zoom Distance: " << zoomDistance << "\n";
	std::cout << "Rotation Distance: " << rotationDistance << "\n\n";*/

	std::cout << fingers << " ";
	if (fingers >= 3)
	{
		if (abs(panDistance) >= abs(zoomDistance) && abs(panDistance) >= abs(rotationDistance))
		{
			std::cout << "finger pan\n";
			std::cout << panDistance << " pixels";
		}
		else if (abs(zoomDistance) >= abs(panDistance) && abs(zoomDistance) >= abs(rotationDistance))
		{
			std::cout << "finger zoom ";
			if (zoomDistance < 0)
			{
				std::cout << "in\n";
				std::cout << abs(zoomDistance) << " pixels";
			}
			else
			{
				std::cout << "out\n";
				std::cout << abs(zoomDistance) << " pixels";
			}
		}
		else
		{
			std::cout << "finger rotate ";
			if (rotationDistance >= 0)
			{
				std::cout << "(direction todo)\n";
				std::cout << rotationAngle * (180.0/M_PI) << " degrees";
			}
			else
			{
				std::cout << "(direction todo)\n";
				std::cout << rotationAngle * (180.0 / M_PI) << " degrees";
			}
		}
	}
	else if (fingers >= 2)
	{
		if (abs(panDistance) >= abs(zoomDistance) && abs(panDistance) >= abs(rotationDistance))
		{
			std::cout << "finger pan\n";
			std::cout << panDistance << " pixels";
		}
		else
		{
			std::cout << "finger zoom ";
			if (zoomDistance < 0)
			{
				std::cout << "in\n";
				std::cout << abs(zoomDistance) << " pixels";
			}
			else
			{
				std::cout << "out\n";
				std::cout << abs(zoomDistance) << " pixels";
			}
		}
	}
	else if (fingers == 1)
	{
		std::cout << "finger pan\n";
		std::cout << panDistance << " pixels";
	}



	std::cout << '\n';
	system("pause");
}