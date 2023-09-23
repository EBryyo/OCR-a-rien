#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int check_line (size_t pos[2], int tab[][16])
{ //done
	//checks if line is valid
	
	size_t x = pos[1];
	size_t y = pos[0];
	int cur = tab[y][x];
	
	for(size_t X = 0; X < 16; X++)
	{
		if (X != x && tab[y][X] == cur)
			return 0;
	}
	return 1;
}

int check_column (size_t pos[2], int tab[][16])
{ //done
	//checks if column is valid
	
	size_t x = pos[1];
	size_t y = pos[0];
	int cur = tab[y][x];
	
	for(size_t Y = 0; Y < 16; Y++)
	{
		if (Y != y && tab[Y][x] == cur)
			return 0;
	}
	return 1;
}

int check_box (size_t pos[2], int tab[][16])
{ //done
	//checks if box is valid
	
	size_t x = pos[1];
	size_t y = pos[0];
	int cur = tab[y][x];
	
	size_t xbias = (x / 4) * 4;
	size_t ybias = (y / 4) * 4;
	
	for (size_t i = ybias; i < ybias + 4; i++)
	{
		for (size_t j = xbias; j < xbias + 4; j++)
		{
			if(!(j == x && i == y) && tab[i][j] == cur)
				return 0;
		}
	}
	return 1;
}

void next (size_t pos[2], int ref[][16])
{ //done
	//moves pos to the next mutable position
	size_t x = pos[1];
	size_t y = pos[0];
	do {
		x = (x + 1) % 16;
		y += !(x);
	} while (ref[y][x] >= 0);
	pos[1] = x;
	pos[0] = y;
}

void prev (size_t pos[2], int ref[][16])
{ //done
	//moves pos to the previous mutable position
	size_t x = pos[1];
	size_t y = pos[0];
	do {
		if (!x)
		{
			y--;
			x = 15;
		}
		else 
			x--;
	} while (ref[y][x] >= 0);
	pos[1] = x;
	pos[0] = y;
}

int possible (size_t pos[2], int tab[][16])
{ //done
	//returns 0 if the current state of the board is impossible, else not 0
	//printf("exec: possible\n");
	return (check_line(pos, tab) && check_column(pos, tab)) && check_box(pos, tab);
}

void mv_next (size_t pos[2], int tab[][16], int ref[][16])
{ //done
	//moves the program forward in the board
	
	size_t x = pos[1];
	size_t y = pos[0];
	
	if (possible(pos,tab))
	{
		next(pos,ref);
		tab[pos[0]][pos[1]]++;
	}
	else tab[y][x]++;
}

void mv_prev (size_t pos[2], int tab[][16], int ref[][16])
{ //done
	//backtracks to next iterable state
	
	size_t x = pos[1];
	size_t y = pos[0];
	
	do {
		tab[y][x] = -1;
		prev(pos,ref);
		x = pos[1];
		y = pos[0];
	} while (tab[y][x] == 15);
	tab[y][x]++;
}


void solve (int tab[][16])
{
	//solving process
	int ref[16][16]; 
	//deep copy of tab,
	//as to know which cells are immutable and which are not.
	for(size_t x = 0; x < 16; x++)
		for(size_t y = 0; y < 16; y++)
			ref[x][y] = tab[x][y];
	size_t p[] = {0,0}; //array representing the current position
	//int i = 0;
	while(1)
	{
		//i++;
		//printf("\033[25A");
		//printf("\033[25D");
		//print_sudoku(tab);
		
		//for(int j = 0; j < 10000; j++)
		//{}
			//iteration
		size_t x = p[1];
		size_t y = p[0];
		
		if (y > 15)
		{
			p[1] = 15;
			p[0] = 15;
			if (possible(p,tab))
				break;
			else 
			{
				p[1] = 15;
				p[0] = 15;
				if (ref[15][15])
					prev(p,ref);
				mv_prev(p,tab,ref);
			}
		}
		if (!possible(p,tab) && tab[y][x] == 15)
			mv_prev(p,tab,ref);
		else 
			mv_next(p,tab,ref);
	}
	
}
