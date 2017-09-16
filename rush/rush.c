#include <stdio.h>

void ft_putchar(char c)
{
	putchar(c);
}

void ft_manage_coord(int col, int line, int cols, int lines)
{
	if ((line == 1 || line == lines) && (col == 1 || col == cols))
		ft_putchar('o');
	else if (col == 1 || col == cols)
		ft_putchar('|');
	else if (line == 1 || line == lines)
		ft_putchar('-');
	else 
		ft_putchar(' ');
}

void colle(int x, int y)
{
	int cols;
	int lines;
	int line;
	int col; 

	cols = x;
	lines = y;
	line = 1;
	col = 1;
	while (line <= lines)
	{
		col = 1;
		while (col <= cols)
		{
			ft_manage_coord(col, line, cols, lines);
			col++;
		}
		ft_putchar('\n');
		line++;
	}
}

int main()
{
	colle(5, 1);
	return (0);
}