#include "ImageFeatures.h"
#include <cmath>

ImageFeatures::ImageFeatures(ContouredImage image)
	: image(image)
{}

double ImageFeatures::Circularity()
{
	Circle boundingCircle = image.GetBoundingCircle();

	return std::max(image.GetArea() / boundingCircle.GetArea(), 1.0f);
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