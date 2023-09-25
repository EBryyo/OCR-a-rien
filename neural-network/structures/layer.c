#include "layer.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

double get(Layer* layer, size_t x, size_t y)
{
    size_t w = layer->w_out;
    return layer->weights[y * w + x];    
}

void set(Layer* layer, size_t x , size_t y, double d)
{
    size_t w = layer->w_out;
    layer->weights[y * w + x] = d;
}

double* compute_output(Layer* layer, double* input, size_t input_len)
{
    double* res = calloc(layer->w_out, sizeof(double));
    size_t w, h;
    w = layer->w_out;
    h = layer->h_in;

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
            res[i] += (input[j] * get(layer, i, j));
        }
    }
    
    return res;
}
