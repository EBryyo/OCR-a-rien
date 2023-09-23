#include <stdio.h>
#include <stddef.h>

void print_img(int rows, int columns, char tab[][columns])
{
	for(size_t y = 0; y < rows; y++)
	{
		for(size_t x = 0; x < columns; x++)
		{
			printf("%c", tab[y][x] < 100 ? '.' : 'O');
		}
	}
}
