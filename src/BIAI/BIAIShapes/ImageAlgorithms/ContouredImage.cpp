#include "ContouredImage.h"
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;

ContouredImage::ContouredImage(cv::Mat image)
{
	cv::Mat canny_output;
	vector<vector<cv::Point> > ctrs;
	vector<cv::Vec4i> hierarchy;
	cv::Canny(image, canny_output, 100, 200);
	cv::findContours(canny_output, ctrs, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);

	if ( ctrs.size() > 0 )
		contour = ctrs[0];
}

vector<cv::Point> ContouredImage::GetContour()
{
	return contour;
}

float ContouredImage::GetArea()
{
	return float(cv::contourArea(contour));
}

Circle ContouredImage::GetBoundingCircle()
{
	cv::Point2f center;
	float radius;
	cv::minEnclosingCircle(contour, center, radius);

	return Circle(radius, center);
}

Box ContouredImage::GetBoundingBox()
{
	cv::Rect rect = cv::boundingRect(contour);

	return Box(rect.size());
}