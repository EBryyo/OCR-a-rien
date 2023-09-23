#include <stddef.h>
#include <stdio.h>


void read_image(size_t n, int rows, int columns, char t[][columns], char* file)
{
	FILE *textfile;
	char byte;
	textfile = fopen(file,"r");
	size_t m = rows*images*n;
	for(size_t = 12; n < m; n++)
	{
		fgetc(textfile);
	}

	for(size_t y = 0; y < rows; y++)
	{
		for(size_t x = 0; x < columns; x++)
		{
			byte = fgetc(textfile);
			t[y][x] = byte;
		}
	}
}

void get_size(char* file, int* rows, int* columns, int* images)
{
	FILE *textfile;
	int i;
	int c;
	int r;

	textfile = fopen(file,"br");
	if (textfile == NULL)
		return;

	fread(&c, 4, 1, textfile);
	fread(&i, 4, 1, textfile);
	fread(&c, 4, 1, textfile);
	fread(&r, 4, 1, textfile);

	*images = i;
	*rows = r;
	*columns = c;
}
