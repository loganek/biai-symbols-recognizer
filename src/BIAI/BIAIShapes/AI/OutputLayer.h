#ifndef OUTPUT_LAYER_H
#define OUTPUT_LAYER_H

#include "FurtherLayer.h"

class OutputLayer : public FurtherLayer
{
public:
	OutputLayer(int neuronCount, Layer* previousLayer);
	void CalculateGradients(const std::vector<double>& expected);
};

#endif