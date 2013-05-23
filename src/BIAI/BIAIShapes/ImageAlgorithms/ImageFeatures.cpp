#include "ImageFeatures.h"
#include <cmath>

ImageFeatures::ImageFeatures(ContouredImage image)
	: image(image)
{}

double ImageFeatures::Circularity()
{
	Circle boundingCircle = image.GetBoundingCircle();

	return std::min(image.GetArea() / boundingCircle.GetArea(), 1.0f);
}

double ImageFeatures::Convexity()
{
	ContouredImage contoured = image.GetConvexHull();

	return std::min(image.GetArea() / contoured.GetArea(), 1.0f);
}

double ImageFeatures::Rectangularity()
{
	Box boundingBox = image.GetBoundingBox();

	return image.GetArea() / boundingBox.GetArea();
}