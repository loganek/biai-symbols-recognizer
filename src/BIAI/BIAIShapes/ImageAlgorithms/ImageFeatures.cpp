#include "ImageFeatures.h"

ImageFeatures::ImageFeatures(ContouredImage image)
	: image(image)
{}

double ImageFeatures::Circularity()
{
	image.GetArea();
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