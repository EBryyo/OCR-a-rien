#include <stddef.h>

#ifndef LAYER_H
#define LAYER_H

typedef struct Layer
{
    size_t w_out; //width of matrix
    size_t h_in; //height of matrix
    double** weights;
}Layer;

double* compute_output(Layer* layer, double* input, size_t input_len);
//computes the outputs of the layer for given inputs

#endif
