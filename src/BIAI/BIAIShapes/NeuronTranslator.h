#ifndef NEURON_TRANSLATOR_H
#define NEURON_TRANSLATOR_H

#include <bitset>
#include <algorithm>

template<int N>
class NeuronTranslator
{
private:
	std::bitset<N> data;
	std::vector<double> original;
public:
	virtual ~NeuronTranslator() {}

	void Init(const std::vector<double>& networkValues)
	{
		if ( networkValues.size() != N )
			throw std::exception("Rozmiar tablicy wejœciowej ró¿ny od rozmiaru kontenera!");

		double max = 0.0;
		int maxIndex = 0;

		data.reset();

		for ( int i = 0; i < N; i++ )
		{
			if ( max < networkValues[i] )
			{
				max = networkValues[i];
				maxIndex = i;
			}
		}

		data.set(maxIndex);

		original.resize(networkValues.size());
		std::copy(networkValues.begin(), networkValues.end(), original.begin());
	}

	int GetSetIndex()
	{
		for ( unsigned i = 0; i < data.size(); i++ )
			if ( data.test(i) )
				return i;

		return -1;
	}

	std::string GetBinaryString()
	{
		std::string str = data.to_string();
		std::reverse(str.begin(), str.end());
		
		return str;
	}

	std::vector<double> GetOriginalData()
	{
		return original;
	}

	static std::vector<double> GenerateNetworkData(int value)
	{
		std::vector<double> out;
		out.reserve(N);
		bitset<N> bs(value);
		
		for ( int i = N - 1; i >= 0; i-- )
			out.push_back(bs.test(i));

		return out;
	}

	static std::vector<double> GenerateIndexedData(int position)
	{
		std::vector<double> out(N, 0);
		
		out[position] = 1.0;

		return out;
	}


};

#endif