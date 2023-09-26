#include "layer.h"
#include "mlp.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

void compute(mlp network, double* input, size_t len, unsigned char output)
{
    return;
}

mlp* import_mlp(char* source)
{
    mlp* res;
    size_t input_len, hidden_len, output_len;
    FILE* file = fopen(source,"rb");


    //allocate memory for the mlp
    res = calloc(1,sizeof(mlp));

    //read layer lengths from source
    fread(&input_len, sizeof(size_t), 1, file);
    fread(&hidden_len, sizeof(size_t), 1, file);
    fread(&output_len, sizeof(size_t), 1, file);

    //add layer lengths to mlp struct
    res->len_input = input_len;
    res->len_hidden = hidden_len;
    res->len_output = output_len;

    size_t m, i;
    //initialize input_layer
    res->input_layer.w_out = input_len;
    res->input_layer.h_in = 1;
    m = input_len;
    //printf("m = %lu\n", m);
    res->input_layer.weights = calloc(m,sizeof(double*));
    for(i = 0; i < 1; i++)
    {
	res->input_layer.weights[i] = calloc(1,sizeof(double));
	fread(res->input_layer.weights[i],sizeof(double),1,file);
    }

    //initalize hidden_layer
    res->hidden_layer.w_out = hidden_len;
    res->hidden_layer.h_in = input_len;
    m = input_len * hidden_len;
    //printf("m = %lu\n", m);
    res->hidden_layer.weights = calloc(m, sizeof(double));
    for(i = 0; i < 1; i++)
    {
	res->hidden_layer.weights[i] = calloc(input_len,sizeof(double));
	fread(res->hidden_layer.weights[i],sizeof(double),input_len,file);
    }

    //initialize output_layer
    res->output_layer.w_out = output_len;
    res->output_layer.h_in = hidden_len;
    m = hidden_len * output_len;
    //printf("m = %lu\n", m);
    res->output_layer.weights = calloc(m, sizeof(double));
    for(i = 0; i < 1; i++)
    {
	res->output_layer.weights[i] = calloc(hidden_len,sizeof(double));
	fread(res->output_layer.weights[i],sizeof(double),hidden_len,file);
    }

    fclose(file);
    printf("flag\n");
    return res;
}

void export_mlp(mlp* n, char* destination)
{ //TO FIX
    FILE* file;
    file = fopen(destination, "wb");

    //write layer lengths
    fwrite(&n->len_input, sizeof(size_t), 1, file);
    fwrite(&n->len_hidden, sizeof(size_t), 1, file);
    fwrite(&n->len_output, sizeof(size_t), 1, file);

    size_t m;

    //write weights for each layer
    m = n->len_input;
    fwrite(n->input_layer.weights, sizeof(double), m, file);
    m = n->len_input * n->len_hidden;
    fwrite(n->hidden_layer.weights, sizeof(double), m, file);
    m = n->len_hidden * n->len_output;
    fwrite(n->output_layer.weights, sizeof(double), m, file);

    fclose(file);
}

void print_mlp(mlp* n)
{
    printf("\ninput layer:\n");
    printf("length : %zu\n", n->len_input);
    for(size_t i = 0; i < n->len_input; i++)
    {
	printf("sigmoid %zu: ", i);
	printf("%lf", n->input_layer.weights[i][0]);
	printf("\n");
    }

    printf("\nhidden layer:\n");
    printf("length : %zu\n", n->len_hidden);
    
    for(size_t i = 0; i < n->len_hidden; i++)
    {
	printf("sigmoid %zu: ", i);
	for(size_t j = 0; j < n->len_input; j++)
	{
	    printf("%lf ", n->hidden_layer.weights[i][j]);
	}
	printf("\n");
    }


    printf("\noutput layer:\n");
    printf("length : %zu\n", n->len_output);

    for(size_t i = 0; i < n->len_output; i++)
    {
	printf("sigmoid %zu: ", i);
	for(size_t j = 0; j < n->len_hidden; j++)
	{
	    printf("%lf ", n->output_layer.weights[i][j]);
	}
	printf("\n");
    }
}
