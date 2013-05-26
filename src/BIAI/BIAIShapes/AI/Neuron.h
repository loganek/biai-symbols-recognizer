#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <functional>

struct Line
{
    double weight;
    double delta;

	Line(double weight = 0.0, double delta = 0.0) : weight(weight), delta(delta) {}
};

class Neuron
{
private:
	double gradient;
	double output;
	unsigned index;
	std::vector<Line> weights;

    std::function<double()> weightsInitializer;

	static double trainRate;
    static double momentum;
public:
	
    Neuron(unsigned outputCount, unsigned index);

	void SetOutput(double val) { output = val; }
    double GetOutput() const { return output; }
	
	double GetWeighted(int i) const { return output * weights[i].weight; }
	
	double GetGradient() const { return gradient; }
	void SetGradient(double value) { gradient = value; }

	double GetWeight(int index) const { return weights[index].weight; }
	void SetWeight(int index, double value) { weights[index].weight = value; }
	int GetWeightCount() const { return weights.size(); }
	
	unsigned GetIndex() const { return index; }
	
	void UpdateWeight(const Neuron& targetNeuron);
};

#endif