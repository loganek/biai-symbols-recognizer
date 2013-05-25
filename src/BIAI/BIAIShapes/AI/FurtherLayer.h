#ifndef FURTHER_LAYER_H
#define FURTHER_LAYER_H

#include "Layer.h"
#include <functional>

class FurtherLayer : public Layer
{
private:
	Layer* previousLayer;

protected:
	std::function<double(double)> activationFunction;
	std::function<double(double)> activationFunctionDerivative;

public:
	FurtherLayer(int neuronCount, Layer* previousLayer, int outputs);
	virtual ~FurtherLayer() {}

	void UpdateInputWeights();
	void FeedForward();
	void SetActivationFunctions(std::function<double(double)> actFun, std::function<double(double)> actFunDer);
};


#endif