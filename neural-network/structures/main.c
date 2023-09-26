#include <stdio.h>
#include <stddef.h>
#include "layer.h"
#include "mlp.h"
#include <stdlib.h>

void main(void)
{
    size_t i;
    mlp* neural_net = calloc(1, sizeof(mlp));
    neural_net->len_input = 3;
    neural_net->len_hidden = 2;
    neural_net->len_output = 1;
    //malloc for input layer
    neural_net->input_layer.weights = calloc(3,sizeof(double*));
    for(i = 0; i < neural_net->len_input; i++)
    {
	neural_net->input_layer.weights[i] = calloc(1,sizeof(double));
    }
    //malloc for hidden layer
    neural_net->hidden_layer.weights = calloc(2, sizeof(double*));
    for(i = 0; i < neural_net->len_hidden; i++)
    {
	neural_net->hidden_layer.weights[i] = calloc(3,sizeof(double));
    }
    //malloc for output layer
    neural_net->output_layer.weights = calloc(1, sizeof(double*));
    neural_net->output_layer.weights[0] = calloc(2, sizeof(double));
    neural_net->input_layer.weights[0][0] = 1;
    neural_net->input_layer.weights[1][0] = 2;
    neural_net->input_layer.weights[2][0] = 3;
    neural_net->hidden_layer.weights[0][0] = -1;
    neural_net->hidden_layer.weights[0][1] = -2;
    neural_net->hidden_layer.weights[1][2] = 3;
    neural_net->hidden_layer.weights[1][0] = -2;
    neural_net->output_layer.weights[0][1] = -2;


    /*
    
    set(&neural_net->input_layer,0,0,1);
    set(&neural_net->input_layer,1,0,2);
    set(&neural_net->input_layer,2,0,-2);
    set(&neural_net->hidden_layer,0,0,1);
    set(&neural_net->hidden_layer,0,1,2);
    set(&neural_net->hidden_layer,0,2,3);
    set(&neural_net->hidden_layer,2,1,0);
    set(&neural_net->hidden_layer,1,1,0);
    set(&neural_net->hidden_layer,1,0,0);
    set(&neural_net->output_layer,0,0,0);
    set(&neural_net->output_layer,0,1,0);
    */

    export_mlp(neural_net, "network");
    
    mlp* n = import_mlp("network");
    print_mlp(neural_net);
    print_mlp(n);
 }
