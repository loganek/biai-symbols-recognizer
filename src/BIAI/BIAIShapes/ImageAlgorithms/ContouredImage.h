#ifndef CONTOURED_IMAGE_H
#define CONTOURED_IMAGE_H

#include "Circle.h"
#include "Box.h"
#include <vector>
#include <opencv2/core/core.hpp>

class ContouredImage
{
private:
	std::vector<cv::Point> contour;
public:
	ContouredImage(const std::string& fileName);
	ContouredImage(const std::vector<cv::Point>& contour);

	std::vector<cv::Point> GetContour();
	float GetArea();
	Circle GetBoundingCircle();
	Box GetBoundingBox();
	ContouredImage GetConvexHull();
};

#endif