#ifndef TRAINING_DATA
#define TRAINING_DATA

#include <fstream>

namespace ShapeNo
{
	enum Type
	{
		CIRCLE = 0,
		SQUARE,
		CROSS,
		TRIANGLE,
	};
}

class TrainingData
{
private:
	float circularity;
	float rectangularity;
	float convexity;
	ShapeNo::Type type;

	friend std::istream & operator >> (std::istream& stream, TrainingData& data);
public:
	TrainingData(float circularity, float rectangularity, float convexity, ShapeNo::Type type);
	TrainingData();

	float GetCircularity() const;
	float GetRectangularity() const;
	float GetConvexity() const;
	ShapeNo::Type GetShapeType() const;
};



#endif