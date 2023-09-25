#ifndef MLP_H
#define MLP_H

typedef struct
{
	sigmoid* input_layer;
	size_t len_input;

	sigmoid* hidden_layers;
    size_t len_hidden;

	sigmoid* output_layer;
	size_t len_output;
} mlp;

void compute(mlp network, double* input, size_t len, unsigned char output);
//computes input array through the MLP and into the output array

mlp* import_mlp( char* source);
//returns mlp encoded at source

void export_mlp(mlp network, char* destination);
//exports sigmoid weights and biases into binary file at destination

void print_mlp(mlp* n);
//prints lengths of all layers
#endif
