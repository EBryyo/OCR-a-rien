#include <stddef.h>



void mv_next(unsigned int pos[2], unsigned int tab[][9], unsigned int ref[][9])
{ //moves the program forward in the board
	
}

void mv_prev(unsigned int pos[2], unsigned int tab[][9], unsigned int ref[][9])
{ //backtracks to next possible state
	
}

unsigned int possible(unsigned int pos[2], unsigned int tab[][9])
{ //returns 0 if the current state of the board is impossible, else not 0
	
}

void solve(unsigned int tab[][9])
{
	unsigned int ref[9][9]; 
	//copy of tab, as to know which cells are immutable and which are not.
	for(size_t x = 0; x < 9; x++)
		for(size_t y = 0; y < 9; y++)
			ref[x][y] = tab[x][y];
	unsigned int p[2] = {0,0}; //array representing the current position
}
