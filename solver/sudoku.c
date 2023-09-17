#include <stddeff.h>

void solve(unsigned int tab[][9])
{
	unsigned int ref[9][9]; 
	//copy of tab, as to know which cells are immutable and which are not.
	for(size_t x = 0; x < 9; x++)
		for(size_t y = 0; y < 9; y++)
			ref[x][y] = tab[x][y];

}
