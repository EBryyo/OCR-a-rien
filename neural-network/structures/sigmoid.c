#include <math.h>
#include <stddef.h>


double fire(sigmoid neuron, double inputs[], size_t len_inputs)
{
	double x, res;
	
	x = 0;
	//compute linear combination of inputs and weights
	for(size_t i = 0; i < len_inputs; i++)
	{
		x += inputs[i] * neuron->weights[i];
	}
	//compute sigmoid function
	res = 1 / (1 + exp(-x));
	return res;
}
