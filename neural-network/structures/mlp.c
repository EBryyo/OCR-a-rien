#include "sigmoid.h"
#include <stdio.h>
#include <stddef.h>

void compute(mlp network, double* input, size_t len, unsigned char output)
{
	return;
}

void compute_layer(mlp network, double* input, double* output, size_t len)
{

}

mlp* import_mlp(, char* source)
{
	mlp* res;
	size_t input_len, hidden_len, output_len;
	FILE* file = fopen(source,"rb");
	
	
	//allocate memory for the mlp
	res = (mlp*) calloc(1,sizeof(mlp));
	
	//add layer lengths to mlp struct
	res*->len_input = input_len;
	res*->len_hidden = hidden_len;
	res*->len_output = output_len;


	return res;
}

void export_mlp(mlp* network, char* destination)
{
    FILE* file;
    file = fopen(destination);
    mlp n = network*
}

void print_mlp(mlp* n)
{
    printf("length of input layer : %z\n", n*->len_input);
    printf("length of hidden layer : %z\n", n*->len_hidden);
    printf("length of output layer : %z\n", n*->len_output);
}
