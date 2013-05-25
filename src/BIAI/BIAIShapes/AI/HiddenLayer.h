#ifndef HIDDEN_LAYER_H
#define HIDDEN_LAYER_H

#include "FurtherLayer.h"

class HiddenLayer : public FurtherLayer
{
public:
	HiddenLayer(int neuronCount, Layer* previousLayer, int outputs);
	virtual ~HiddenLayer() {}

	void CalculateGradients(Layer* nextLayer);
};

#endif
