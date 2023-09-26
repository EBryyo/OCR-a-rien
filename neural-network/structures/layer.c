#include "layer.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

double* compute_output(Layer* layer, double* input, size_t input_len)
{
    double* res = calloc(layer->w, sizeof(double));
    size_t w, h;
    w = layer->w;
    h = layer->h;

    if (input_len != h)
    {
        printf("mismatch in matrix dimensions\n");
        return res;
    }

    for(size_t i = 0; i < w; i++)
    {
        res[i] = 0;
        for(size_t j = 0; j < h; j++)
        {
            res[i] += (input[j] * layer->weights[i][j]);
        }
    }
    
    return res;
}
