#include <stddef.h>


unsigned int check_line (unsigned int pos[2], unsigned int tab[][9])
{ 
	//checks if line is valid
	unsigned int x = pos[1];
	unsigned int y = pos[0];
	unsigned int cur = tab[y][x];
	for(size_t X = 0; X < 9; X++)
	{
		if (X != x && tab[y][X] == cur)
			return 0;
	}
	return 1;
}

unsigned int check_column (unsigned int pos[2], unsigned int tab[][9])
{
	//checks if column is valid
	unsigned int x = pos[1];
	unsigned int y = pos[0];
	unsigned int cur = tab[y][x];
	for(size_t Y = 0; Y < 9; Y++)
	{
		if (Y != y && tab[Y][x] == cur)
			return 0;
	}
	return 1;
}

unsigned int check_box (unsigned int pos[2], unsigned int tab[][9])
{
	//checks if box is valid
	unsigned int x = pos[1];
	unsigned int y = pos[0];
	unsigned int cur = tab[y][x];
	unsigned int xbias = (x / 3) * 3;
	unsigned int ybias = (y / 3) * 3;
	for (size_t i = ybias; i < ybias + 3; i++)
	{
		for (size_t j = xbias; j < xbias + 3; j++)
		{
			if(!(j == x && i == y) && tab[i][j] == cur)
				return 0;
		}
	}
	return 1;
}

unsigned int check (unsigned int pos[2], unsinged int tab[][9])
{
	//all checks. returns if current cell is valid
	return (check_line(pos, tab) && check_column(pos, tab)) && check_box(pos, tab);
}

void mv_next (unsigned int pos[2], unsigned int tab[][9], unsigned int ref[][9])
{ 
	//moves the program forward in the board
	
}

void mv_prev (unsigned int pos[2], unsigned int tab[][9], unsigned int ref[][9])
{ 
	//backtracks to next possible state
	
}

unsigned int possible (unsigned int pos[2], unsigned int tab[][9])
{ 
	//returns 0 if the current state of the board is impossible, else not 0
	
}

void solve (unsigned int tab[][9])
{
	//solving process
	unsigned int ref[9][9]; 
	//deep copy of tab,
	//as to know which cells are immutable and which are not.
	for(size_t x = 0; x < 9; x++)
		for(size_t y = 0; y < 9; y++)
			ref[x][y] = tab[x][y];
	unsigned int p[2] = {0,0}; //array representing the current position
}
