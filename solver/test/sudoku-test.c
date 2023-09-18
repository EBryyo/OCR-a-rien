#include <stddef.h>
#include <stdio.h>
#include "print-sudoku.h"
#include <stdlib.h>

unsigned int check_line (size_t pos[2], unsigned int tab[][9])
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

unsigned int check_column (size_t pos[2], unsigned int tab[][9])
{
	//checks if column is valid
	
	size_t x = pos[1];
	size_t y = pos[0];
	unsigned int cur = tab[y][x];
	
	for(size_t Y = 0; Y < 9; Y++)
	{
		if (Y != y && tab[Y][x] == cur)
			return 0;
	}
	return 1;
}

unsigned int check_box (size_t pos[2], unsigned int tab[][9])
{
	//checks if box is valid
	
	size_t x = pos[1];
	size_t y = pos[0];
	unsigned int cur = tab[y][x];
	
	size_t xbias = (x / 3) * 3;
	size_t ybias = (y / 3) * 3;
	
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

void next (size_t pos[2], unsigned int ref[][9])
{
	//moves pos to the next mutable position
	size_t x = pos[1];
	size_t y = pos[0];
	do {
		x = (x + 1) % 9;
		y += !(x);
	} while (ref[y][x]);
	pos[1] = x;
	pos[0] = y;
}

void prev (size_t pos[2], unsigned int ref[][9])
{
	//moves pos to the previous mutable position
	size_t x = pos[1];
	size_t y = pos[0];
	do {
		if (!x)
		{
			y--;
			x = 8;
		}
		else 
			x--;
	} while (ref[y][x]);
	pos[1] = x;
	pos[0] = y;
}

unsigned int possible (size_t pos[2], unsigned int tab[][9])
{ 
	//returns 0 if the current state of the board is impossible, else not 0
	//printf("exec: possible\n");
	return (check_line(pos, tab) && check_column(pos, tab)) && check_box(pos, tab);
}

void mv_next (size_t pos[2], unsigned int tab[][9], unsigned int ref[][9])
{ 
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

void mv_prev (size_t pos[2], unsigned int tab[][9], unsigned int ref[][9])
{ 
	//backtracks to next iterable state
	
	size_t x = pos[1];
	size_t y = pos[0];
	
	do {
		tab[y][x] = 0;
		prev(pos,ref);
		x = pos[1];
		y = pos[0];
	} while (tab[y][x] == 9);
	tab[y][x]++;
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
	size_t p[] = {0,0}; //array representing the current position
	unsigned int i = 0;
	while(1)
	{
		i++;
		printf("\033[20A");
		printf("\033[20D");
		print_sudoku(tab);
		
		for(unsigned int j = 0; j < 100000000; j++)
		{}
			//iteration
		size_t x = p[1];
		size_t y = p[0];
		
		if (y > 8)
		{
			if (possible(p,tab))
				break;
			else 
			{
				p[1] = 8;
				p[0] = 8;
				if (ref[8][8])
					prev(p,ref);
				mv_prev(p,tab,ref);
			}
		}
		if (!possible(p,tab) && tab[y][x] == 9)
			mv_prev(p,tab,ref);
		else 
			mv_next(p,tab,ref);
	}
	
}
