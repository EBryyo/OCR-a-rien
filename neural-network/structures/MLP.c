#include "sigmoid.h"
#include <stdio.h>
#include <stddef.h>

typedef struct
{
	sigmoid input_layer[];
	sigmoid hidden_layer[];
	sidmoid output_layer[];
} MLP;
