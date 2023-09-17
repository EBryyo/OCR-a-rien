#include "print-sudoku.h"
#include "sudoku.h"
#include <stddef.h>
#include <stdio.h>

int main(void)
{
	unsigned int tab[9][9];
	//for(size_t x = 0; x < 9; x++)
	//	for(size_t y = 0; y < 9; y++)
	//		tab[x][y] = 2;
	FILE* ptr;
	char c;
	
	//extract board from ./board

	ptr = fopen("board","r");
	size_t x = 0;
	size_t y = 0;
	while (!feof(ptr))
	{
		c = fgetc(ptr);
		if (c == '\n')
		{
			x = 0;
			y++;
		}
		else
			tab[y][x++] = c - '0';
	}


	//display board
	print_sudoku(tab);

	solve(tab);

	print_sudoku(tab);
	return 0;
}
