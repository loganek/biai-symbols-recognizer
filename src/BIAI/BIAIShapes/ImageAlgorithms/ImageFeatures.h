#ifndef IMAGE_FEATURES_H
#define IMAGE_FEATURES_H

#include "ContouredImage.h"

class ImageFeatures
{
private:
	ContouredImage image;
public:
	ImageFeatures(ContouredImage image);
	virtual ~ImageFeatures() {}

	double Circularity();
	double Convexity();
	double Rectangularity();
};

#endif