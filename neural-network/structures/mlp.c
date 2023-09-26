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
    mlp* n;
    FILE* file = fopen(source,"rb");


    //allocate memory for the mlp
    n = calloc(1,sizeof(mlp));

    //read layer lengths from source into corresponding res fields
    fread(&n->len_input, sizeof(size_t), 1, file);
    fread(&n->len_hidden, sizeof(size_t), 1, file);
    fread(&n->len_output, sizeof(size_t), 1, file);


    size_t x, y, i;

    //initialize and complete input_layer

    x = n->len_input;
    y = 1;
    n->input_layer.w = x;
    n->input_layer.h = y;
    n->input_layer.weights = calloc(x,sizeof(double*));
    for(i = 0; i < x; i++)
    {
        n->input_layer.weights[i] = calloc(y,sizeof(double));
        fread(n->input_layer.weights[i], sizeof(double), y, file);
    }

    //initalize and complete hidden_layer

    x = n->len_hidden;
    y = n->len_input;
    n->input_layer.w = x;
    n->input_layer.h = y;
    n->input_layer.weights = calloc(x,sizeof(double*));
    for(i = 0; i < x; i++)
    {
        n->input_layer.weights[i] = calloc(y,sizeof(double));
        fread(n->input_layer.weights[i], sizeof(double), y, file);
    }

    //initialize and complete output_layer

    x = n->len_output;
    y = n->len_hidden;
    n->input_layer.w = x;
    n->input_layer.h = y;
    n->input_layer.weights = calloc(x,sizeof(double*));
    for(i = 0; i < x; i++)
    {
        n->input_layer.weights[i] = calloc(y,sizeof(double));
        fread(n->input_layer.weights[i], sizeof(double), y, file);
    }

    fclose(file);
    return n;
}

void export_mlp(mlp* n, char* destination)
{ //TO FIX
    FILE* file;
    file = fopen(destination, "wb");

    //write layer lengths
    fwrite(&n->len_input, sizeof(size_t), 1, file);
    fwrite(&n->len_hidden, sizeof(size_t), 1, file);
    fwrite(&n->len_output, sizeof(size_t), 1, file);

    size_t m, i;

    //write weights for each layer
    m = n->len_input;
    for(i = 0; i < m; i++)
    {
        fwrite(&n->input_layer.weights[i], sizeof(double),1, file);
    }
    m = n->len_input * n->len_hidden;
    for(i = 0; i < m; i++)
    {
        fwrite(&n->hidden_layer.weights[i], sizeof(double), n->len_input, file);
    }
    m = n->len_hidden * n->len_output;
    for(i = 0; i < m; i++)
    {
        fwrite(&n->output_layer.weights[i], sizeof(double), n->len_hidden, file);
    }
    
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
