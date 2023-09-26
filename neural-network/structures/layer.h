#include <stddef.h>

#ifndef LAYER_H
#define LAYER_H

typedef struct Layer
{
    size_t w; //width of matrix, number of sigmoids
    size_t h; //height of matrix, number of inputs/weights
    double** weights;
    double* biases;
}Layer;

double* compute_output(Layer* layer, double* input, size_t input_len);
//computes the outputs of the layer for given inputs

#endif
