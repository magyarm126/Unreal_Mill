#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(const int Hidden_Layer_Count_Param, const int Neuron_Count_Per_Layer_Param)
{
	Hidden_Layer_Count = Hidden_Layer_Count_Param;
	Neuron_Count_Per_Layer = Neuron_Count_Per_Layer_Param;
	Layer_Count = Hidden_Layer_Count + 1;

	Topology = new std::vector<NeuronLayer>();
	Topology->resize(Layer_Count, NeuronLayer(Neuron_Count_Per_Layer_Param));

	for (int i = 0; i < Topology->size(); i++)
	{
		for (int j = 0; j < (*Topology)[i].size(); j++)
		{
			(*Topology)[i][j] = new Neuron(j, nullptr);
		}
	}
}
