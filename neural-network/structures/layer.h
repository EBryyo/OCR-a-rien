#include <stddef.h>

#ifndef LAYER_H
#define LAYER_H

typedef struct Layer
{
    size_t w_out; //width of matrix
    size_t h_in; //height of matrix
    double* weights;
}Layer;

double get(Layer* layer, size_t x, size_t y);
//returns layer->weights[y][x]

void set(Layer* layer, size_t x, size_t y, double d);
//sets layer->weights[y][x] to d

double* compute_output(Layer* layer, double* input, size_t input_len);
//computes the outputs of the layer for given inputs

#endif
