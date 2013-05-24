#include "ContouredImage.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

ContouredImage::ContouredImage(const std::string& fileName)
{
	cv::Mat image = cv::imread(fileName);
	cv::Mat gray;
	cvtColor(image, gray, CV_BGR2GRAY);
	cv::blur(gray, gray, cv::Size(3,3));
	cv::Mat canny_output;
	vector<vector<cv::Point> > ctrs;
	vector<cv::Vec4i> hierarchy;
	cv::Canny(image, canny_output, 100, 200);
	cv::findContours(canny_output, ctrs, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);

	if ( ctrs.size() > 0 )
		contour = ctrs[0];
}

ContouredImage::ContouredImage(const vector<cv::Point>& contour)
	: contour(contour)
{}

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

ContouredImage ContouredImage::GetConvexHull()
{
	vector<cv::Point> convHull;
	cv::convexHull(contour, convHull);

	return ContouredImage(convHull);
}