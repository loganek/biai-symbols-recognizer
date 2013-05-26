#include "MainProgram.h"
#include "Training/Training.h"
#include "AI/NetworkIO.h"
#include "ImageAlgorithms/ImageFeatures.h"
#include "NeuronTranslator.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void MainProgram::DisplayMenu(const char* appName)
{
	cout << "Uzywanie programu:" << endl;
	cout << appName << " n network image" << endl;
	cout << "\tklasyfikuje ksztalt" << endl;
	cout << "\tnetwork - sciezka do zapisanej sieci neuronowej" << endl;
	cout << "\timage - sciezka do pliku z obrazem zawierajacym ksztalt" << endl << endl;

	cout << appName << " g data output it" << endl;
	cout << "\tgeneruje now¹ siec na podstawie danych uczacych" << endl;
	cout << "\tdata - dane uczace" << endl;
	cout << "\toutput - sziezka zapisu sieci" << endl;
	cout << "\tit - liczba iteracji uczacych" << endl << endl;

	cout << appName << " h" << endl;
	cout << "\twyswietla te pomoc" << endl << endl;
}

void MainProgram::ParseArguments(int argc, char** argv)
{
	if ( argc < 1 )
	{
		DisplayMenu("BIAIShapes.exe");
		return;
	}

	if ( argc < 2 )
	{
		DisplayMenu(argv[0]);
		return;
	}

	try
	{
		if ( strcmp(argv[1], "g") == 0 )
		{
			GenerateNetwork(argc, argv);
			return;
		}

		if ( strcmp(argv[1], "n") == 0 )
		{
			ProcessImage(argc, argv);
			return;
		}
	}
	catch ( exception ex )
	{
		cout << "Wystapil blad podczas dzialania programu: " << ex.what() << endl;
	}

	DisplayMenu(argv[0]);
}

void MainProgram::ProcessImage(int argc, char** argv)
{
	if ( argc != 4 )
		throw exception("Podano niepoprawna ilosc argumentow dla polecenia");

	ContouredImage image(argv[3]);
	ImageFeatures features(image);

	cout << "Okraglosc: " << features.Circularity() << endl;
	cout << "Wypuklosc: " << features.Convexity() << endl;
	cout << "Kwadratowosc: " << features.Rectangularity() << endl;

	vector<double> featVect;
	featVect.push_back(features.Circularity());
	featVect.push_back(features.Convexity());
	featVect.push_back(features.Rectangularity());

	NetworkIO netIO(argv[2]);
	NeuralNetwork* network = netIO.LoadNetwork();

	network->FeedForward(featVect);
	NeuronTranslator<3> translator;
	translator.Init(network->GetResults());

	cout << "Siec wykazala, ze podany ksztalt to " << ShapeToStr((ShapeNo::Type)translator.GetSetIndex()) << endl;

	delete network;
}

const char* MainProgram::ShapeToStr(ShapeNo::Type shape)
{
	switch (shape)
	{
	case ShapeNo::CIRCLE:
		return "circle";
	case ShapeNo::CROSS:
		return "cross";
	case ShapeNo::SQUARE:
		return "square";
	default:
		return "unknow";
	}
}

void MainProgram::GenerateNetwork(int argc, char** argv)
{
	if ( argc != 5 )
		throw exception("Podano niepoprawna ilosc argumentow dla polecenia");

	vector<int> hiddenLayers;
	hiddenLayers.push_back(4);
	hiddenLayers.push_back(5);

	TopologyInfo info;
	info.inputCount = 3;
	info.outputCount = 3;
	info.hiddenCount = hiddenLayers;

	NeuralNetwork net(info);

	Training training(&net);
	training.LoadTrainingData(argv[2]);
	training.StartTraining(atoi(argv[4]));

	NetworkIO io(argv[3]);
	io.SaveNetwork(&net);

	cout << endl << "Zakonczono proces uczenia z powodzeniem!" << endl;
}