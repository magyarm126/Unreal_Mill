#pragma once
#include <vector>

#include "Neuron.h"

typedef std::vector<Neuron*> NeuronLayer;
typedef std::vector<NeuronLayer> Topology;

class NeuralNetwork
{
	int Hidden_Layer_Count;
	int Layer_Count;

	int Neuron_Count_Per_Layer;
	Topology* Topology;

public:
	NeuralNetwork(const int Hidden_Layer_Count_Param, const int Neuron_Count_Per_Layer_Param);
};
