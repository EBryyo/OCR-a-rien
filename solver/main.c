#include "print-sudoku.h"
#include "sudoku.h"
#include <stddef.h>


int main(void)
{
	unsigned int tab[9][9];
	for(size_t x = 0; x < 9; x++)
		for(size_t y = 0; y < 9; y++)
			tab[x][y] = 2;

	print_sudoku(tab);
	return 0;
}
