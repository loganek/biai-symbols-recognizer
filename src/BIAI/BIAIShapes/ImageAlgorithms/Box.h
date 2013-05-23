#ifndef BOX_H
#define BOX_H

#include <opencv2/core/core.hpp>

class Box
{
private:
	cv::Size2f size;
	cv::Point2i location;
public:
	Box(cv::Size2f size, cv::Point2i location = cv::Point2i(0, 0))
		: size(size), location(location)
	{}

	cv::Size GetSize()
	{
		return size;
	}

	cv::Point2i GetLocation()
	{
		return location;
	}

	float GetArea()
	{
		return size.area();
	}
};

#endif