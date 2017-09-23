#include <unistd.h>
#include <stdio.h>

// De verificat caractere in plus 
// De verificat ca sirul are lungimea potrivita

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen (char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int test_with (int x, int y, int nb, int mat[9][9])
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (mat[x][i] == nb)
			return 0;
		if (mat[i][y] == nb)
			return 0;
		if (mat[(x / 3) * 3 + i % 3][(y / 3) * 3 + i / 3] == nb)
			return 0; 
		i++;
	}
	return 1;
}

void print_mat(int mat[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j  = 0;
		while (j < 9)
		{
			if (mat[i][j] != -1)
				ft_putchar(mat[i][j] + '0');
			else 
				ft_putchar('.');
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void solve(int x, int y, int mat[9][9])
{
	int i;

	if (y == 9)
	{
		print_mat(mat);
		return ;
	}
	if (mat[x][y] == -1)
	{
		i = 1;
		while (i <= 9)
		{
			if (test_with(x, y, i, mat))
			{
				mat[x][y] = i;
				solve((x + 1) % 9, (y + (x + 1) / 9), mat); 
				mat[x][y] = -1;
			}
			i++;
		}
	}
	else {
		solve((x + 1) % 9, (y + (x + 1) / 9), mat);
	}
}

int main(int argc, char *argv[])
{
	int i;
	int j;
	int mat[9][9];

	if (argc != 10)
	{
		write(1, "Erreur\n", 7);
		return 0;
	}

	i = 1;
	j = 0;
	while (i < argc)
	{
		int j = 0;
		if (ft_strlen(argv[i]) != 9)
		{
			write(1, "Erreur\n", 7);
			return 0;
		}
		while (argv[i][j])
		{
			if (!(argv[i][j] == '.' || (argv[i][j] >= '0' && argv[i][j] <= '9')))
			{
				write(1, "Erreur\n", 7);
				return 0;
			}
			if (argv[i][j] != '.')
				mat[i - 1][j] = argv[i][j] - '0';
			else
				mat[i - 1][j] = -1;
			j++;
		}
		i++;
	}
	solve(0, 0, mat);
	return 0;
}