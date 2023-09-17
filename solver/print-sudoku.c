#include <stdio.h>
#include <stddef.h>

void print_sudoku(unsigned int tab[][9])
{
	for(size_t y = 0; y < 9; y++)
	{
		if (!(y % 3)) printf("\n");
		for(size_t x = 0; x < 9; x++)
		{
			if (!(x % 3)) printf(" ");
			//pretty printing UwU
			unsigned int i = tab[x][y];
			if (i) printf("%u", i);
			else printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}
