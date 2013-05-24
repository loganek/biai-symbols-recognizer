#include "TrainingData.h"

using namespace std;

TrainingData::TrainingData(float circularity, float rectangularity, float convexity, ShapeNo::Type type)
	: circularity(circularity), rectangularity(rectangularity), convexity(convexity), type(type)
{}

TrainingData::TrainingData()
	: circularity(0.0f), rectangularity(0.0f), convexity(0.0f)
{}

float TrainingData::GetCircularity() const
{
	return circularity;
}

float TrainingData::GetRectangularity() const 
{
	return rectangularity;
}

float TrainingData::GetConvexity() const
{
	return convexity;
}

ShapeNo::Type TrainingData::GetShapeType() const
{
	return type;
}


istream& operator >> (istream& stream, TrainingData& data)
{
	stream >> data.circularity;
	stream >> data.rectangularity;
	stream >> data.convexity;
	stream >> (int&)data.type;

	return stream;
}