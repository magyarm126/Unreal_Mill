#pragma once

class Neuron
{
	const int Index;
	float (* const Activation_Function)();
	float Weight = 0;
	float Output = 0;

public:
	Neuron(const int Index_Param, float (*Activation_Function_Param)()) :
		Index(Index_Param),
		Activation_Function(Activation_Function_Param)
	{
	}
};
