#ifndef CIRCLE_H
#define CIRCLE_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <opencv2/core/core.hpp>

class Circle
{
private:
	float radius;
	cv::Point center;
public:
	Circle(float radius, cv::Point center)
		: radius(radius),
		center(center)
	{}

	cv::Point GetCenter()
	{
		return center;
	}

	float GetRadius()
	{
		return radius;
	}

	float GetArea()
	{
		return std::pow(radius, 2.0f) * float(M_PI);
	}
};

#endif