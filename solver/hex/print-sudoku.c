#include <stdio.h>
#include <stddef.h>

void print_sudoku(int tab[][16])
{
	printf("\n");
	for(size_t y = 0; y < 16; y++)
	{
		if (!(y % 4)) printf("\n");
		for(size_t x = 0; x < 16; x++)
		{
			if (!(x % 4)) printf(" ");
			//pretty printing UwU
			int i = tab[y][x];
			//if (i) printf("%u", i);
			//else printf("_");
			if (i == -1)
				printf("_");
			else
				printf("%c", i <= 9 ? i + '0' : i - 10 + 'A');
		}
		printf("\n");
	}
	printf("\n");
}
