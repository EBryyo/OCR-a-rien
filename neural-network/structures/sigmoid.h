#ifndef SIGMOID_H
#define SIGMOID_H

typedef struct
{
	double* weights;
	size_t len_weights;
	double bias;
} sigmoid;

double fire(sigmoid neuron, double inputs[], size_t len_inputs);
//calculates output from inputs, weights and bias

#endif
