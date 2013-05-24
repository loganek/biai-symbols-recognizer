#ifndef TRAINGING_DATA_LOADER_H
#define TRAINGING_DATA_LOADER_H

#include "TrainingData.h"
#include <vector>
#include <string>
#include <fstream>

template<typename T>
class TrainingDataLoader
{
private:
	std::vector<T> data;
	std::string fileName;
public:
	TrainingDataLoader(const std::string& fileName)
		: fileName(fileName)
	{}
	void LoadData();
	
	std::vector<TrainingData> GetData()
	{
		return data;
	}
};

template<typename T>
void TrainingDataLoader<T>::LoadData()
{
	std::ifstream file;

	file.open(fileName, ios::in);

	if ( !file.is_open() )
		throw std::exception("Nie mo¿na otworzyæ pliku.");

	T tmp;

	while ( file.good() )
	{
		file >> tmp;
		data.push_back(tmp);
	}

	file.close();
}

#endif