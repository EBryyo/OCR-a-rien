#include <stdio.h>
#include <stddef.h>
#include "layer.h"
#include "mlp.h"
#include <stdlib.h>

void main(void)
{
    /*
    mlp* neural_net = calloc(1, sizeof(mlp));
    neural_net->len_input = 3;
    neural_net->len_hidden = 2;
    neural_net->len_output = 1;
    neural_net->input_layer.weights = calloc(3, sizeof(double));
    neural_net->hidden_layer.weights = calloc(6, sizeof(double));
    neural_net->output_layer.weights = calloc(3, sizeof(double));
    
    export_mlp(neural_net, "network");
    */
    mlp* neural_net = import_mlp("network");
    print_mlp(neural_net);
 }
