#ifndef IMAGE_FEATURES_H
#define IMAGE_FEATURES_H

#include <opencv2/core/core.hpp>

class ImageFeatures
{
private:
	cv::Mat image;
public:
	ImageFeatures(cv::Mat image);
	virtual ~ImageFeatures() {}

	double Circularity();
	double Convexity();
	double Elongation();
	double Rectangularity();
};

#endif