#include "print-sudoku.h"
#include "sudoku-test.h"
#include <stddef.h>
#include <stdio.h>


int main(void)
{
	int tab[16][16];
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
		{
			if (c == ' ') 
				tab[y][x++] = -1;
			else 
				tab[y][x++] = c > '9' ? 10 + c - 'A' : c - '0';
		}
	}

	//printf("\033[25A");
	//printf("\033[25D");
	//display board
	print_sudoku(tab);
	
	solve(tab);

	print_sudoku(tab);
	//print_sudoku(tab);
	return 0;
}
