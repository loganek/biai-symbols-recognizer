#include "ImageFeatures.h"

ImageFeatures::ImageFeatures(cv::Mat image)
	: image(image)
{}

double ImageFeatures::Circularity()
{
	return 0.0f;
}

double ImageFeatures::Convexity()
{
	return 0.0f;
}

double ImageFeatures::Elongation()
{
	return 0.0f;
}

double ImageFeatures::Rectangularity()
{
	return 0.0f;
}