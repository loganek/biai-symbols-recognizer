#ifndef CONTOURED_IMAGE_H
#define CONTOURED_IMAGE_H

#include <vector>
#include <opencv2/core/core.hpp>

class ContouredImage
{
private:
	std::vector<cv::Point> contour;
public:
	ContouredImage(cv::Mat image);

	std::vector<cv::Point> GetContour();
	float GetArea();
	float GetRadiusOfBoundingCircle();
};

#endif